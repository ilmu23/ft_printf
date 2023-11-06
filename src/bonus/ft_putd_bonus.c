/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:55:20 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/05 19:32:06 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

static int	putleft(int n, int ndigits, int *flags);
static int	putright(int n, int ndigits, int *flags);
static int	ft_intlen(int n, int *flags);

int	ft_putd(va_list args, int *flags)
{
	int	n;
	int	ndigits;

	if (flags[3] > 0)
	{
		flags[1] = 0;
		ndigits = flags[3];
	}
	else
		ndigits = 0;
	n = va_arg(args, int);
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags));
	if (n < 0)
		ndigits++;
	return (putright(n, ndigits, flags));
}

static int	putleft(int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	nlen = ft_intlen(n, flags);
	if (n < 0)
		nlen--;
	ret = putpadding(ndigits - nlen, '0', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putnbr_fd(n, 1);
	if (n < 0)
		n = -n;
	out += ret;
	ret = putpadding(flags[2] - out, ' ', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	nlen = ft_intlen(n, flags);
	if (ndigits < nlen)
		ndigits = nlen;
	if (flags[1] == 1)
		ret = putpadding(flags[2] - nlen, '0', &n, flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(ndigits - nlen, '0', &n, flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putnbr_fd(n, 1);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	ft_intlen(int n, int *flags)
{
	int	digits;

	digits = 1;
	if (n >= 0 && n <= 9 && flags[5] > 0)
		digits--;
	if (n == INT_MIN)
		n++;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
