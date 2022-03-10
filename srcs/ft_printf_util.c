/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:10:23 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/11 00:49:29 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static	char	*ft_tostring(char *str, int i, long long int n)
{
	size_t	div;

	div = 10;
	while ((n / div) != 0)
		div = div * 10;
	div = div / 10;
	while (div != 0)
	{
		str[i++] = (n / div) + '0';
		n = n % div;
		div = div / 10;
		if (!div)
			break ;
	}
	str[i] = '\0';
	return (str);
}

static	size_t	ft_checklength(long long int n)
{
	size_t	div;
	size_t	i;

	div = 1;
	i = 0;
	while ((n / div) != 0)
	{
		i++;
		div = div * 10;
	}
	if (n == 0)
		i = 1;
	return (i);
}

char	*ft_utoa(long long int n)
{
	size_t		size;
	int			neg;
	char		*str;
	long long int	nbr;
	size_t		i;

	neg = 0;
	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		neg = 1;
		nbr = nbr * (-1);
	}
	size = ft_checklength(nbr);
	str = malloc(sizeof(char) * (size + neg + 1));
	if (!str)
		return (0);
	if (neg)
		str[i++] = '-';
	return (ft_tostring(str, i, nbr));
}

int    ft_print_base(long long int nbr, char *base, int basenb)
{
	char    temp;
	int	len;

	len = 0;
	if (!(nbr / basenb))
	{
		temp = base[nbr % basenb];
		len += write(1, &temp, 1);
		return (len);
	}
	len += ft_print_base(nbr / basenb, base, basenb);
	temp = base[nbr % basenb];
	len += write(1, &temp, 1);
	return (len);
}