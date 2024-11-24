/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexamol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:11:16 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/24 21:43:26 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	tanchof4(t_flags a, char hexa)
{
	int	size;

	size = 0;
	if (a.hashtag == 1)
	{
		if (hexa == 'x')
			size += ft_putstr("0x");
		else if (hexa == 'X')
			size += ft_putstr("0X");
	}
	return (size);
}

int	hexamol(unsigned long n, char hexa, int a, t_flags hh)
{
	int			size;
	static int	i;
	char		*str;

	size = 0;
	if (hexa == 'x' || hexa == 'p')
		str = "0123456789abcdef";
	if (hexa == 'X')
		str = "0123456789ABCDEF";
	if (a == 0)
		i = 0;
	if (i == 0)
		size += tanchof4(hh, hexa);
	i = 1;
	if (n >= 16)
	{
		size += hexamol(n / 16, hexa, 1, hh);
	}
	size += ft_putchar(str[n % 16]);
	return (size);
}
