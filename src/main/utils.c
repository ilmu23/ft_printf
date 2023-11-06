/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:11:50 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/03 19:23:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_strupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

char	*ft_strrev(char *s)
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

int	hexlen(unsigned long long n)
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
