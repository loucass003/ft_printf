/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:03:04 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/20 15:09:03 by llelievr         ###   ########.fr       */
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

static void		*memcpy2(uint16_t *dst, uint16_t *src, size_t *i)
{
	*i -= 2;
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
		if (n >= 4 && n < 8)
			memcpy4((uint32_t *)dst, (uint32_t *)src, &n);
		if (n >= 2 && n < 4)
			memcpy2((uint16_t *)dst, (uint16_t *)src, &n);
		if (n == 1)
			memcpy1((uint8_t *)dst, (uint8_t *)src, &n);
	}
	return (dst);
}
