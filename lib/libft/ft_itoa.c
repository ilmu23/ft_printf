/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/24 18:40:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *s);
static size_t	ft_intlen(int n);

char	*ft_itoa(int n)
{
	int		neg;
	char	*out;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	out = ft_calloc(ft_intlen(n) + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		out[i++] = n % 10 + '0';
		n /= 10;
	}
	out[i++] = n + '0';
	if (neg == 1)
		out[i] = '-';
	return (ft_strrev(out));
}

static char	*ft_strrev(char *s)
{
	char	tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
	return (s);
}

static size_t	ft_intlen(int n)
{
	size_t	digits;

	digits = 1;
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
