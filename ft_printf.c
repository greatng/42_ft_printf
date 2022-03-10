/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:39:35 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/11 02:05:01 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	ft_eval_format(t_print *tab, const char *format, int i)
{

	if (format[i] == '%')
		tab->tl += (write(1, "%", 1));
	else if (format[i] == 'c')
		tab->tl += ft_print_c(tab);
	else if (format[i] == 's')
		tab->tl += ft_print_s(tab);
	else if (format[i] == 'p')
		tab->tl += ft_print_p(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		tab->tl += ft_print_nb(tab);
	else if (format[i] == 'u')
		tab->tl += ft_print_u(tab);
	else if (format[i] == 'x')
		tab->tl += ft_print_x(tab, 'x');
	else if (format[i] == 'X')
		tab->tl += ft_print_x(tab, 'X');
	else tab->error = 1;
	return (1);
}

static int	ft_finalize(t_print *tab, int ret)
{
	int	tl;

	tl = tab->tl;
	if (tab->error)
	{
		free (tab);
		return (-1);
	} 
	free (tab);
	return (ret + tl);
}
static t_print	*ft_initialise_tab(t_print *tab)
{
	tab->tl = 0;
	tab->error = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	ret;
	t_print	*tab;
	
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i += ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret = ft_finalize(tab , ret);
	return (ret);
}
