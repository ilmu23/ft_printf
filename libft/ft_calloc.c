/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2023/10/26 17:12:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	asize;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	asize = count * size;
	if (asize > MAX_ALLOC)
		return (NULL);
	if (asize < count && asize < size)
		return (NULL);
	out = malloc(count * size);
	if (!out)
		return (NULL);
	ft_bzero(out, count * size);
	return (out);
}
