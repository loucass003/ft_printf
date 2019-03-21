/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:31:38 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 14:46:58 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t			abs_uintmaxt(intmax_t n)
{
	return (n < 0 ? -n : n);
}

intmax_t			mint(intmax_t a, intmax_t b)
{
	return (a < b ? a : b);
}

intmax_t			maxt(intmax_t a, intmax_t b)
{
	return (a > b ? a : b);
}

long double			abs_ld(long double a)
{
	return (a < 0 ? -a : a);
}

long double			powld(long double n, int pow)
{
	long double	out;

	if (pow == 0)
		return (1);
	out = 1;
	if (pow < 0)
		n = 1 / n;
	pow = ft_abs(pow);
	while (--pow >= 0)
		out *= n;
	return (out);
}
