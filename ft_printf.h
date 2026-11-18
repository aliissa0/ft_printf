/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:12:20 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/18 16:55:58 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	size_t 	width;
	int	prec;
	char	speci;
}		t_flag;

int		ft_printf(const char *str, ...);
int		ft_handlemod(va_list *lst, char const *str);
void	ft_init_flags(t_flag *new);
int		ft_isspec(char c);
int		ft_isflag(char c);
void	ft_setprec(t_flag *flag, char const *str, int *i);
void	ft_parser(char const *str, int *i, t_flag *flag);
void	ft_print_char(t_flag flag, int c);
void	ft_print_str(t_flag flag, char *str);
char	*ft_strcat(char *dest, char *src);
void	ft_print_nb(t_flag s_flag, int nbr);
char	*ft_ltoa_base(long nb, char *base_to);
int		ft_countdigit(long nb, int leng);
int		ft_ischar(int c);


#endif