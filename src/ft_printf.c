/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:54:11 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/13 17:16:57 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;
	int		out;

	if (!s)
		return (ft_putstr_fd((char *)s, 1));
	ret = 1;
	out = 0;
	va_start(args, s);
	while (*s && ret >= 0)
	{
		if (*s != '%')
			ret = ft_putchar_fd(*s, 1);
		else
		{
			s++;
			ret = ft_printformat(&s, args);
		}
		out += ret;
		s++;
	}
	va_end(args);
	if (ret < 0)
		return (-1);
	return (out);
}

int	ft_printformat(const char **f, va_list args)
{
	if (!(**f))
		return (0);
	if (**f == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_putarg(f, args));
}
