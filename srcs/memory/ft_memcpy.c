/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:03:04 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/20 14:57:58 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*memcpy8(uint64_t *dst, uint64_t *src, size_t n)
{
	while (n > 0)
	{
		n -= 8;
		dst[n] = src[n];
	}
	return (dst);
}

static void		*memcpy4(uint32_t *dst, uint32_t *src, size_t n)
{
	while (n > 0)
	{
		n -= 4;
		dst[n] = src[n];
	}
	return (dst);
}

static void		*memcpy2(uint16_t *dst, uint16_t *src, size_t n)
{
	while (n > 0)
	{
		n -= 2;
		dst[n] = src[n];
	}
	return (dst);
}

static void		*memcpy1(uint8_t *dst, uint8_t *src, size_t n)
{
	while (n-- > 0)
		dst[n] = src[n];
	return (dst);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (n >= 8)
		return (memcpy8((uint64_t *)dst, (uint64_t *)src, n));
	if (n >= 4)
		return (memcpy4((uint32_t *)dst, (uint32_t *)src, n));
	if (n >= 2)
		return (memcpy2((uint16_t *)dst, (uint16_t *)src, n));
	return (memcpy1((uint8_t *)dst, (uint8_t *)src, n));
}
