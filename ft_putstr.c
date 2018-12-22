/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:45:21 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/08 22:05:16 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *s)
{
	char const	*c;

	if (!s)
		return ;
	c = s;
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
}
