/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:28 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/27 20:32:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	long	out;
	long	prev;
	int		n;

	n = 1;
	out = 0;
	while (ft_isspace(*str) != 0)
		str++;
	if (*str == '-')
		n = -n;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		prev = out;
		out = out * 10 + (*str - '0');
		if ((prev > 0 && out < 0) || (prev < 0 && out > 0))
		{
			if (n < 0)
				return (0);
			return (-1);
		}
		str++;
	}
	return (out * n);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
