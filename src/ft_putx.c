/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:09:45 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/11 18:49:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*uitox(unsigned int n);

int	ft_putx(unsigned int n, char format)
{
	char	*s;
	int		out;

	s = uitox(n);
	if (!s)
		return (-1);
	if (format == 'X')
		ft_strupper(s);
	out = ft_putstr_fd(s, 1);
	free(s);
	return (out);
}

static char	*uitox(unsigned int n)
{
	const char	hexarr[] = "0123456789abcdef";
	size_t		i;
	char		*out;
	int			xlen;

	xlen = hexlen((unsigned long long)n);
	out = ft_calloc(xlen + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (n > 15)
	{
		out[i++] = hexarr[n % 16];
		n /= 16;
	}
	out[i++] = hexarr[n % 16];
	ft_strrev(out);
	return (out);
}
