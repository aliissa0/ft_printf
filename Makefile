# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/17 22:58:52 by aliissa           #+#    #+#              #
#    Updated: 2026/11/21 20:26:54 by aliissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRC			= ft_printf.c ft_printaddr.c ft_printnb.c ft_printchar.c

BONUS_SRC	= ft_printf_bonus.c helper_bonus.c helper2_bonus.c \
			  printchar_bonus.c printnb_bonus.c printhx_bonus.c \
			  printadr_bonus.c

OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(RM) .bonus
	$(AR) $(NAME) $(OBJ)

bonus: .bonus

.bonus:	$(BONUS_OBJ)
	$(RM) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJ)
	touch .bonus

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%_bonus.o: %_bonus.c ft_printf_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: %.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) .bonus

re: fclean all

.PHONY: all bonus clean fclean re