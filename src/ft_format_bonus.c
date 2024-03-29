/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:23 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/13 17:05:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_bonus.h"

static char	*parseformat(const char *f, int *flags, va_list args);
static char	*getflags(const char *f, int *flags);
static void	parseflag(const char c, int *flags);
static int	getvalue(const char *f, va_list args);

int	ft_putarg(const char **f, va_list args)
{
	int	flags[6];

	*f = parseformat(*f, flags, args);
	if (**f == '%')
		return (ft_putc(args, flags, '%'));
	if (**f == 'c')
		return (ft_putc(args, flags, 'c'));
	if (**f == 'd' || **f == 'i')
		return (ft_putd(args, flags));
	if (**f == 'u')
		return (ft_putu(args, flags));
	if (**f == 's')
		return (ft_puts(args, flags));
	if (**f == 'x' || **f == 'X')
		return (ft_putx(args, flags, **f));
	if (**f == 'p')
		return (ft_putp(args, flags));
	*f = *f - 1;
	return (0);
}

static char	*parseformat(const char *f, int *flags, va_list args)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[4] = 0;
	flags[5] = 0;
	f = getflags(f, flags);
	flags[2] = getvalue(f, args);
	while (ft_isdigit(*f) == 1 || *f == '*')
		f++;
	flags[3] = -1;
	if (*f == '.')
	{
		f++;
		flags[1] = 0;
		flags[3] = getvalue(f, args);
		while (ft_isdigit(*f) == 1 || *f == '*')
			f++;
	}
	return ((char *)f);
}

static char	*getflags(const char *f, int *flags)
{
	while (ft_contains("# +-0", *f) == 1)
	{
		parseflag(*f, flags);
		f++;
	}
	return ((char *)f);
}

static void	parseflag(const char c, int *flags)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0' && flags[0] == 0)
		flags[1] = 1;
	else if (c == '#')
		flags[4] = 1;
	else if (c == '+')
		flags[5] = 1;
	else if (c == ' ' && flags[5] == 0)
		flags[5] = 2;
}

static int	getvalue(const char *f, va_list args)
{
	if (*f == '*')
		return (va_arg(args, int));
	if (ft_isdigit(*f) > 0)
		return (ft_atoi(f));
	return (0);
}
