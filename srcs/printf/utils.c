/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:31:38 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 20:36:29 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	downcast(t_subsp sp, uintmax_t nb, t_bool unsign)
{
	if (unsign)
	{
		if (sp == sp_hh)
			return ((unsigned char)nb);
		if (sp == sp_h)
			return ((unsigned short)nb);
	}
	else
	{
		if (sp == sp_hh)
			return ((char)nb);
		if (sp == sp_h)
			return ((short)nb);
	}
	return (nb);
}

int		get_flag(char c)
{
	if (c == '+')
		return (f_plus);
	if (c == '-')
		return (f_minus);
	if (c == '0')
		return (f_zero);
	if (c == '#')
		return (f_hash);
	if (c == ' ')
		return (f_space);
	return (0);
}

uintmax_t		abs_uintmaxt(intmax_t n)
{
	return (n < 0 ? -n : n);
}

intmax_t			min(intmax_t a, intmax_t b)
{
	return (a < b ? a : b);
}

intmax_t			max(intmax_t a, intmax_t b)
{
	return (a > b ? a : b);
}