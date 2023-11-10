/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:31 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/10 16:45:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkflags(int n, int *flags);
static int	checkrvals(int rv1, int rv2);

int	ft_putnbr_fd(int n, int fd, int *flags)
{
	int	ret;
	int	out;

	out = 0;
	if (n < 0 && checkflags(n, flags) == 1)
	{
		n = -n;
		out = ft_putchar_fd('-', fd);
	}
	if (n == INT_MIN)
	{
		ret = ft_putunbr_fd(2147483648, fd);
		return (checkrvals(out, ret));
	}
	if (n > 9)
	{
		ret = ft_putnbr_fd(n / 10, fd, flags);
		out += ret;
		ret = ft_putchar_fd(n % 10 + '0', fd);
		if (ret < 0 || out < 1)
			return (-1);
		return (out + ret);
	}
	return (checkrvals(out, ft_putchar_fd(n + '0', fd)));
}

static int	checkflags(int n, int *flags)
{
	if (n != INT_MIN)
		return (1);
	if (!flags)
		return (1);
	if (flags[0] == 1 && flags[3] < 11)
		return (1);
	if (flags[2] == 0 && flags[3] == 0)
		return (1);
	if (flags[1] == 1 && flags[2] < (int)ft_intlen(n) && flags[3] < 11)
		return (1);
	if (flags[1] != 1 && flags[3] < 11)
		return (1);
	return (0);
}

static int	checkrvals(int rv1, int rv2)
{
	if (rv1 < 0 || rv2 < 0)
		return (-1);
	return (rv1 + rv2);
}
