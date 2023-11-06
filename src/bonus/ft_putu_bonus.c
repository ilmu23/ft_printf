/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:26:06 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/03 18:57:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

static int	putleft(unsigned int n, int ndigits, int *flags);
static int	putright(unsigned int n, int ndigits, int *flags);
static int	ft_uintlen(unsigned int n);

int	ft_putu(va_list args, int *flags)
{
	unsigned int	n;
	int				ndigits;

	if (flags[3] > 0)
	{
		flags[1] = 0;
		ndigits = flags[3];
	}
	else
		ndigits = 0;
	n = va_arg(args, unsigned int);
	if (flags[0] == 1)
		return (putleft(n, ndigits, flags));
	return (putright(n, ndigits, flags));
}

static int	putleft(unsigned int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	nlen = ft_uintlen(n);
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putunbr_fd(n, 1);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - (ndigits + nlen), ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(unsigned int n, int ndigits, int *flags)
{
	int	nlen;
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	nlen = ft_uintlen(n);
	if (ndigits < nlen)
		ndigits = nlen;
	if (flags[1] == 1)
		ret = putpadding(flags[2] - nlen, '0', &flags[0], flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(ndigits - nlen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putunbr_fd(n, 1);
	if (ret < 0)
		return (-1);
	return (out + ret);
}

static int	ft_uintlen(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
