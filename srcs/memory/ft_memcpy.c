/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:03:04 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/20 17:24:06 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*memcpy8(uint64_t *dst, uint64_t *src, size_t *i)
{
	*i -= 8;
	dst[*i] = src[*i];
	return (dst);
}

static void		*memcpy4(uint32_t *dst, uint32_t *src, size_t *i)
{
	*i -= 4;
	dst[*i] = src[*i];
	return (dst);
}

static void		*memcpy1(uint8_t *dst, uint8_t *src, size_t *i)
{
	--*i;
	dst[*i] = src[*i];
	return (dst);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n > 0)
	{
		if (n >= 8)
			memcpy8((uint64_t *)dst, (uint64_t *)src, &n);
		else if (n >= 4)
			memcpy4((uint32_t *)dst, (uint32_t *)src, &n);
		else
			memcpy1((uint8_t *)dst, (uint8_t *)src, &n);
	}
	return (dst);
}
