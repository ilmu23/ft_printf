/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:31 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/01 18:26:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;
	int	out;

	out = 0;
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		out = 1;
	}
	if (n > 9)
	{
		ret = ft_putnbr_fd(n / 10, fd);
		out += ret;
		ret = ft_putchar_fd(n % 10 + '0', fd);
		if (ret < 0 || out < 1)
			return (-1);
		return (out + ret);
	}
	return (out + ft_putchar_fd(n + '0', fd));
}
