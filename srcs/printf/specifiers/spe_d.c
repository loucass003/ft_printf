/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 23:31:46 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_d(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str	str;
	size_t		len;
	intmax_t	dval;

	str = ft_uint_to_str(abs_uintmaxt(dval = downcast(f->sub_sp, i.i, FALSE)));
	len = str.len + max(f->precision - str.len, 0) + !!(f->flags & f_space)
		+ (dval < 0 || f->flags & f_plus);
	if (f->precision >= 0 && f->flags & f_zero)
		f->flags ^= f_zero;
	if (f->width > len && !(f->flags & f_minus))
		repeat_char(inst, f->flags & f_zero ? '0' : ' ', f->width - len);
	if (f->flags & f_space)
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
