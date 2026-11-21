# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/17 22:58:52 by aliissa           #+#    #+#              #
#    Updated: 2026/11/21 12:53:41 by aliissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/17 22:58:52 by aliissa           #+#    #+#              #
#    Updated: 2026/11/21 12:55:00 by aliissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

SRC			= ft_printf.c helper.c helper2.c printchar.c printnb.c \
			  printhx.c printadr.c
BONUS_SRC	= ft_printf_bonus.c helper_bonus.c helper2_bonus.c \
			  printchar_bonus.c printnb_bonus.c printhx_bonus.c \
			  printadr_bonus.c

OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(RM) .bonus
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJ)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJ)
	touch .bonus

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%_bonus.o: %_bonus.c ft_printf_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: %.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) .bonus

re: fclean all

.PHONY: all bonus clean fclean re