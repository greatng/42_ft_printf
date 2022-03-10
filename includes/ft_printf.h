/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:45:49 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/11 01:46:54 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>

typedef	struct s_print
{
	va_list	args;
	int	tl;
	int	error;
}	t_print;

int	ft_printf(const char *, ...);
int	ft_print_c(t_print *tab);
int	ft_print_s(t_print *tab);
int	ft_print_nb(t_print *tab);
int	ft_print_u(t_print *tab);
int	ft_print_p(t_print *tab);
int	ft_print_x(t_print *tab, char u);

int    ft_print_base(long long nbr, char *base, int basenb);
char	*ft_utoa(long long n);

#endif