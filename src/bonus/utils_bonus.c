/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:52:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/05 18:54:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

static int	putprefix(int spaces, int *sign, int flag);

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

int	ft_contains(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	putpadding(int spaces, char c, int *sign, int *flags)
{
	int	ret;
	int	out;

	out = 0;
	ret = 0;
	if (c == '0' && (*sign < 0 || flags[5] > 0))
	{
		ret = putprefix(spaces, sign, flags[5]);
		out += ret;
	}
	while (spaces > 0 && ret >= 0)
	{
		ret = ft_putchar_fd(c, 1);
		out += ret;
		spaces--;
	}
	if (ret < 0)
		return (-1);
	return (out);
}

static int	putprefix(int spaces, int *sign, int flag)
{
	if (*sign < 0 && spaces > 0)
	{
		*sign = *sign * -1;
		return (ft_putchar_fd('-', 1));
	}
	if (flag == 1 && *sign >= 0)
		return (ft_putchar_fd('+', 1));
	if (flag == 2 && *sign >= 0)
		return (ft_putchar_fd(' ', 1));
	return (0);
}
