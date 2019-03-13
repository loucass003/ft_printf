/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/13 13:22:23 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_x(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str16	str;
	uintmax_t	len;

	str = ft_uint_to_str16(downcast(f->sub_sp, i.i, TRUE), f->specifier == 'X');
	if (f->precision >= 0 && f->flags & f_zero)
		f->flags ^= f_zero;
	if (f->precision == 0 && i.i == 0)
		str.len = 0;
	f->precision = maxt(f->precision, str.len
		- (f->flags & f_hash ? 2 : 0));
	len = str.len + maxt(f->precision - str.len, 0)
		+ (f->flags & f_hash && i.i != 0 ? 2 : 0);
	if (f->flags & f_zero)
		f->precision = str.len + f->width - len;
	if (f->width > len && !(f->flags & f_minus) && !(f->flags & f_zero))
		repeat_char(inst, f->flags & f_zero ? '0' : ' ', f->width - len);
	if (f->flags & f_hash && i.i != 0)
		write_buf(inst, f->specifier == 'X' ? "0X" : "0x", 2);
	if (f->precision > str.len)
		repeat_char(inst, '0', f->precision - str.len);
	write_buf(inst, str.str, str.len);
	if (f->width > len && f->flags & f_minus)
		repeat_char(inst, ' ', f->width - len);
	return (str.len);
}
