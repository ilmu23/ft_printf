/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:45 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/10 15:25:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

int	ft_uintlen(unsigned int n)
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

int	ft_hexlen(unsigned int n)
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
