/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:19:20 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/15 22:02:52 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (1)
	{
		n = n / 10;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

static int		check_min_neg(int *n, unsigned int *sign)
{
	unsigned int	flag;

	flag = 0;
	if (*n < 0)
	{
		*sign = 1;
		if (*n == -2147483648)
		{
			*n = *n / 10;
			flag = 1;
		}
		*n = -(*n);
	}
	return (flag);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	sign;

	len = nbrlen(n);
	str = ft_strnew(len);
	if (!str)
		return (str);
	sign = 0;
	if (check_min_neg(&n, &sign))
		*(str + --len) = '8';
	while (len)
	{
		if (len == 1 && sign)
			*str = '-';
		else
			*(str + len - 1) = (char)('0' + n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}
