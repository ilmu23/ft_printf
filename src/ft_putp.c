/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:24:03 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/12 15:54:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*ptox(unsigned long n);

int	ft_putp(unsigned long addr)
{
	char	*s;
	int		out;

	s = ptox(addr);
	if (!s)
		return (-1);
	out = ft_putstr_fd(s, 1);
	free(s);
	return (out);
}

static char	*ptox(unsigned long n)
{
	const char	hexarr[] = "0123456789abcdef";
	size_t		i;
	char		*tmp;
	char		*out;
	int			xlen;

	xlen = hexlen(n);
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
