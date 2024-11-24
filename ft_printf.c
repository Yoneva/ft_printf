/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:15:46 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/25 00:25:40 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 int if_p(char c, int i, t_flags hh, va_list args)
 {
	void	*s;
		s = va_arg(args, void *);
		if (s)
			return (ft_putstr("0x") + hexamol((unsigned long)s, c, i, hh));
		return (ft_putstr("0x") + ft_putstr("0"));
 }
int	conditions(char c, va_list args, t_flags hh)
{
	int		i;

	i = 0;
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (hexamol(va_arg(args, long), c, i, hh));
	else if (c == 'X')
		return (hexamol(va_arg(args, long), c, i, hh));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int), c, hh, i));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), c, hh, i));
	else if (c == 'p')
	{
		return (if_p(c, i, hh, args));
	}
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else 
		return (ft_putchar(c));
	return (0);
}

t_flags	tanchof(char *c)
{
	int		i;
	t_flags	a;

	i = 0;
	a.hashtag = 0;
	a.plus = 0;
	a.space = 0;
	if (!c)
		return (a);
	while (c[i])
	{
		if (c[i] == ' ')
			a.space = 1;
		else if (c[i] == '+')
			a.plus = 1;
		else if (c[i] == '#')
			a.hashtag = 1;
		else 
			break ;
		i++;
	}
	return (a);
}

int	tanchof3(int i, const char *s)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '+' && s[i] != '#')
			break ;
		i++;
	}
	return (i);
}

int chikharya(char *s, int i)
{
	int	size;

	size = 0;
	if (s[i] == '%')
		return (size);
	else
		size += write(1, &s[i], 1);
	return (size);
}
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;
	int		g;
	t_flags	bonus;

	size = 0;
	i = 0;
	g = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			bonus = tanchof((char *)s + i);
			i = tanchof3(i, s);
			size += conditions(s[i], args, bonus);
		}
		else
			size +=chikharya((char *)s, i);
		i++;
	}
	va_end(args);
	return (size);
}

// int main()
// {
// 	printf(" dyali %d \n",ft_printf("this %#x, %#X, % +d\n" ,1234567890, 1234567890, -1234567890));
// 	printf(" dyalhm %d \n",printf("this %#x, %#X, % +d\n" , 1234567890, 1234567890, -1234567890));
// }
