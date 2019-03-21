/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 15:19:55 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_types	subsp_arg_di(t_format *fmt, t_specifier spe)
{
	if (fmt->sub_sp == sp_l || fmt->sub_sp == sp_ll)
		return (fmt->sub_sp == sp_l ? LONG : LLONG);
	if (fmt->sub_sp == sp_j)
		return (INTMAX);
	if (fmt->sub_sp == sp_z)
		return (SIZET);
	return (spe.default_arg);
}

int		specifier_d(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str	str;
	uintmax_t	len;
	intmax_t	dval;

	dval = downcast(f->sub_sp, i.i, FALSE);
	str = ft_uint_to_str(abs_uintmaxt(dval));
	str.len = f->precision == 0 && i.i == 0 ? 0 : str.len;
	len = str.len + maxt(f->precision - str.len, 0)
		+ (f->flags & f_space && dval >= 0) + (dval < 0 || f->flags & f_plus);
	if (f->precision >= 0 && f->flags & f_zero)
		f->flags ^= f_zero;
	if (f->flags & f_zero)
		f->precision = str.len + f->width - len;
	if (f->width > len && !(f->flags & f_minus) && !(f->flags & f_zero))
		repeat_char(inst, ' ', f->width - len);
	if (f->flags & f_space && dval >= 0)
		write_buf(inst, " ", 1);
	if ((dval < 0 || f->flags & f_plus))
		write_buf(inst, dval < 0 ? "-" : "+", 1);
	if (f->precision > str.len)
		repeat_char(inst, '0', f->precision - str.len);
	write_buf(inst, str.str, str.len);
	if (f->width > len && f->flags & f_minus)
		repeat_char(inst, ' ', f->width - len);
	return (len);
}
