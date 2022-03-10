/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:59:26 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/11 00:40:39 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_c(t_print *tab)
{
	int	c;
	c = va_arg(tab->args, int);
	if (c)
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	tab->error = 1;
	return (0);
}

int	ft_print_s(t_print *tab)
{
	char	*s;
	s = va_arg(tab->args, char *);
	if (s)
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	} else
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null"));
	}
	tab->error = 1;
	return (0);
}

int	ft_print_nb(t_print *tab)
{
	int	nb;
	nb = va_arg(tab->args, int);
	ft_putnbr_fd(nb, 1);
	return (ft_strlen(ft_itoa(nb)));
}

int	ft_print_u(t_print *tab)
{
	unsigned int	u;
	char	*s;
	int	len;

	u = va_arg(tab->args, unsigned int);
	s = ft_utoa(u);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_print_p(t_print *tab)
{
	unsigned long	p;
	int	len;

	p = va_arg(tab->args, unsigned long);
	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_base(p, "0123456789abcdef", 16);
	return (len);
}