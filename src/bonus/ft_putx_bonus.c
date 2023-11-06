/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:09:20 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/03 21:59:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

static int	hexlen(unsigned int n);
static int	putleft(char *s, int ndigits, int *flags);
static int	putright(char *s, int ndigits, int *flags);
static char	*uitox(unsigned int n, int ndigits);

int	ft_putx(va_list args, int *flags, char format)
{
	unsigned int	n;
	char			*s;
	int				ndigits;
	int				out;

	if (flags[3] > 0)
		ndigits = flags[3];
	else
		ndigits = 0;
	n = va_arg(args, unsigned int);
	s = uitox(n, ndigits);
	if (!s)
		return (-1);
	if (format == 'X')
		ft_strupper(s);
	if (flags[4] == 0 || n == 0)
		s = s + 2;
	if (flags[0] == 1)
		out = putleft(s, ndigits, flags);
	else
		out = putright(s, ndigits, flags);
	if (flags[4] == 0 || n == 0)
		s = s - 2;
	free(s);
	return (out);
}

static int	putleft(char *s, int ndigits, int *flags)
{
	int	slen;
	int	ret;
	int	out;

	out = 0;
	slen = ft_strlen(s);
	ret = putpadding(ndigits - slen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putstr_fd(s, 1);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(flags[2] - (ndigits + slen), ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putright(char *s, int ndigits, int *flags)
{
	int	slen;
	int	ret;
	int	out;

	out = 0;
	slen = ft_strlen(s);
	if (ndigits < slen)
		ndigits = slen;
	if (flags[1] == 1)
		ret = putpadding(flags[2] - slen, '0', &flags[0], flags);
	else
		ret = putpadding(flags[2] - ndigits, ' ', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = putpadding(ndigits - slen, '0', &flags[0], flags);
	out += ret;
	if (ret < 0)
		return (-1);
	ret = ft_putstr_fd(s, 1);
	out += ret;
	if (ret < 0)
		return (-1);
	return (out);
}

static char	*uitox(unsigned int n, int ndigits)
{
	const char	hexarr[] = {'0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t		i;
	char		*out;
	char		*tmp;
	int			xlen;

	xlen = hexlen(n);
	if (ndigits > xlen)
		tmp = ft_calloc(ndigits + 1, sizeof(char));
	else
		tmp = ft_calloc(xlen + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (n > 15)
	{
		tmp[i++] = hexarr[n % 16];
		n /= 16;
	}
	tmp[i++] = hexarr[n];
	ft_strrev(tmp);
	out = ft_strjoin("0x", tmp);
	free(tmp);
	return (out);
}

static int	hexlen(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n > 15)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}
