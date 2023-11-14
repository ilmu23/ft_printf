/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:31:08 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/13 17:14:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include "libft.h"
# include <stdarg.h>

// ft_printf.c
int		ft_printf(const char *s, ...);
int		ft_printformat(const char **f, va_list args);

// ft_format.c
int		ft_putarg(const char **f, va_list args);

// ft_putx.c
int		ft_putx(unsigned int n, char format);

// ft_putp.c
int		ft_putp(unsigned long addr);

// utils.c
void	ft_strupper(char *s);
char	*ft_strrev(char *s);
int		hexlen(unsigned long n);

#endif
