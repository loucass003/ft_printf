/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 22:50:19 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_o(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str8	str;
	size_t		len;

	str = ft_uint_to_str8(downcast(f->sub_sp, i.i, TRUE));
	len = str.len + max(f->precision - str.len, 0);
	if (f->width > len && !(f->flags & f_minus))
		repeat_char(inst, f->flags & f_zero ? '0' : ' ', f->width - len);
	f->precision = str.len + !!(f->flags & f_hash);
	if (f->precision > str.len)
		repeat_char(inst, '0', f->precision - str.len);
	write_buf(inst, str.str, str.len);
	if (f->width > len && f->flags & f_minus)
		repeat_char(inst, ' ', f->width - len);
	return (str.len);
}
