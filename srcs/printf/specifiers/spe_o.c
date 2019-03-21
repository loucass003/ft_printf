/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 14:43:46 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_o(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str8	str;
	uintmax_t	len;

	str = ft_uint_to_str8(downcast(f->sub_sp, i.i, TRUE));
	if (f->precision >= 0 && f->flags & f_zero)
		f->flags ^= f_zero;
	if (f->precision == 0 && i.i == 0 && !(f->flags & f_hash))
		str.len = 0;
	if (i.i == 0 && f->flags & f_hash)
		f->flags ^= f_hash;
	f->precision = maxt(f->precision - !!(f->flags & f_hash), str.len);
	len = str.len + maxt(f->precision - str.len, 0) + !!(f->flags & f_hash);
	if (f->width > len && !(f->flags & f_minus))
		repeat_char(inst, f->flags & f_zero ? '0' : ' ', f->width - len);
	if (f->flags & f_hash)
		write_buf(inst, "0", 1);
	if (f->precision > str.len)
		repeat_char(inst, '0', f->precision - str.len);
	write_buf(inst, str.str, str.len);
	if (f->width > len && f->flags & f_minus)
		repeat_char(inst, ' ', f->width - len);
	return (str.len);
}
