/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:50:55 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 20:30:26 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_addreturn(int *count, int re);
int		ft_putchars(int c);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nb(int nbr);
int		ft_print_add(unsigned long addr);
int		ft_print_hexu(unsigned int addr);
int		ft_print_hexl(unsigned int addr);
int		ft_print_uns(unsigned int nbr);
char	*ft_ltoa_base(unsigned long nb, char *base_to);
size_t	ft_strlen(char const *str);

#endif