/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:10:42 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/14 11:13:46 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_p(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str16	str;
	uintmax_t	len;

	str = ft_uint_to_str16(i.i, FALSE);
	len = 2 + str.len;
	if (len < f->width && !(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - len);
	write_buf(inst, "0x", 2);
	write_buf(inst, str.str, str.len);
	if (len < f->width && f->flags & f_minus)
		repeat_char(inst, ' ', f->width - len);
	return (0);
}
