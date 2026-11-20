/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:12:20 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/20 18:38:30 by aliissa          ###   ########.fr       */
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
	int 	width;
	int		prec;
	char	speci;
}		t_flag;

int		ft_printf(const char *str, ...);
int		ft_handlemod(va_list *lst, char const *str);
void	ft_init_flags(t_flag *new);
int		ft_isspec(char c);
int		ft_isflag(char c);
void	ft_setprec(t_flag *flag, char const *str, int *i);
void	ft_parser(char const *str, int *i, t_flag *flag);
int		ft_print_char(t_flag flag, int c);
int		ft_print_str(t_flag flag, char const *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_ltoa_base(long nb, char *base_to, t_flag flag);
int		ft_countdigit(long nb, int leng);
int		ft_ischar(int c);
int		ft_putcharn(char c, int count);
int		ft_putstrs(char const *s, int len);
int		ft_putchars(char c);
void	ft_addreturn(int *count, int re);
int		ft_print_nb(t_flag flag, int nbr);
int		ft_print_nb(t_flag flag, int nbr);
int		ft_print_add(t_flag flag, int p);
int		ft_print_uns(t_flag flag, unsigned int	nbr);
int		ft_print_hexl(t_flag flag, unsigned int nbr);
int		ft_print_hexu(t_flag flag, unsigned int nbr);

#endif