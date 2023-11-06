/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:01:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/28 18:02:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	ret;
	int	out;

	out = 0;
	if (n > 9)
	{
		ret = ft_putnbr_fd(n / 10, fd);
		out += ret;
		ret = ft_putchar_fd(n % 10 + '0', fd);
		if (ret < 0 || out < 1)
			return (-1);
		return (out + ret);
	}
	return (ft_putchar_fd(n + '0', fd));
}
