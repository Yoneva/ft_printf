/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:07:51 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/25 00:08:50 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
#include <stdio.h>

typedef struct a_flags{
	int	space;
	int	hashtag;
	int	plus;
}	t_flags;

int		ft_putchar(char c);
int		ft_putnbr(long n, char hexa, t_flags a, int c);
int		ft_putstr(char *s);
int		ft_strlen(char *str);
int		hexamol(unsigned long n, char c, int a, t_flags hh);

#endif