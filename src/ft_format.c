/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:00:04 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/13 17:17:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_putarg(const char **f, va_list args)
{
	if (**f == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (**f == 'd' || **f == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, NULL));
	if (**f == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	if (**f == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (**f == 'x' || **f == 'X')
		return (ft_putx(va_arg(args, unsigned int), **f));
	if (**f == 'p')
		return (ft_putp(va_arg(args, unsigned long)));
	*f = *f - 1;
	return (0);
}
