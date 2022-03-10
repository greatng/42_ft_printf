/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:38:22 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/11 01:20:40 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

int	ft_print_x(t_print *tab, char u)
{
	unsigned long	x;
	int	len;

	x = va_arg(tab->args, unsigned long);
	len = 0;
	if (u == 'x')
		len += ft_print_base(x, "0123456789abcdef", 16);
	else	
		len += ft_print_base(x, "0123456789ABCDEF", 16);
	return (len);
}