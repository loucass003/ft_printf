/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 17:06:38 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_d(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str	str;
	size_t		r;
	size_t		len;

	str = ft_int_to_str(downcast(f->sub_sp, i.i, FALSE), f->flags & f_plus);
	r = -1;
	if (f->flags & f_space)
		write_buf(inst, " ", 1);
	printf("%d\n", f->width - f->precision);
	if (f->width > f->precision - str.len && !(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - f->precision);
	if (f->precision > str.len - !!(f->flags & f_plus))
		repeat_char(inst, '0', f->precision - (str.len - !!(f->flags & f_plus)));
	write_buf(inst, str.str, str.len);
	if (f->flags & f_minus)
		repeat_char(inst, ' ', f->width - f->precision);
	return (str.len);
}
