/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:52:26 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/11 18:47:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_BONUS_H
# define FTPRINTF_BONUS_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

// ft_printf_bonus.c
int		ft_printf(const char *s, ...);
int		ft_printformat(const char **f, va_list args);

// ft_format_bonus.c
int		ft_putarg(const char **f, va_list args);

// ft_putc_bonus.c
int		ft_putc(va_list args, int *flags, char format);

// ft_putd_bonus.c
int		ft_putd(va_list args, int *flags);

// ft_putu_bonus.c
int		ft_putu(va_list args, int *flags);

// ft_puts_bonus.c
int		ft_puts(va_list args, int *flags);

// ft_putx_bonus.c
int		ft_putx(va_list args, int *flags, char format);

// ft_putp_bonus.c
int		ft_putp(va_list args, int *flags);

// utils_bonus.c
int		ft_contains(char *s, char c);
int		ft_hexlen(unsigned long long n);
int		putpadding(int spaces, char c, int *sign, int *flags);

#endif
