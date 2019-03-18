/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:01:06 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/18 18:21:23 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	abs_ld(long double a)
{
	return (a < 0 ? -a : a);
}

long double	powld(long double n, int pow)
{
	long double	out;

	if (pow == 1)
		return (n);
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

void		computeld(t_format *f, t_int_str *s_ipart, t_int_str *s_dpart,
	long double d)
{
	uintmax_t	ipart;
	uintmax_t	dpart;

	d += (5. * powld(10, -f->precision - 1)) * (d < 0 ? -1. : 1.);
	ipart = abs_uintmaxt(d);
	dpart = (long double)(abs_ld(d) - ipart) * powld(10, f->precision);
	*s_ipart = ft_uint_to_str(ipart);
	*s_dpart = ft_uint_to_str(dpart);
}

void		writeld(t_printf *inst, t_format *f,
	t_int_str *s_ipart, t_int_str *s_dpart)
{
	write_buf(inst, s_ipart->str, s_ipart->len);
	if (f->precision == 0 && !(f->flags & f_hash))
		return ;
	write_buf(inst, ".", 1);
	if ((f->precision <= 1 && s_dpart->len == 1 && s_dpart->str[0] == '0') || f->precision == 0)
		return ;
	write_buf(inst, s_dpart->str, s_dpart->len);
	if (f->precision > s_dpart->len)
		repeat_char(inst, '0', f->precision - s_dpart->len);
}

int			specifier_f(t_arg i, t_printf *inst, t_format *f)
{
	t_int_str	s_ipart;
	t_int_str	s_dpart;
	uintmax_t	len;

	if (f->precision == -1)
		f->precision = 6;
	computeld(f, &s_ipart, &s_dpart, i.d);
	len = s_ipart.len + 1 + s_dpart.len + (f->precision - s_dpart.len) + (!!(f->flags & f_plus) || i.d < 0) + !!(f->flags & f_space);
	if (f->width > len && !(f->flags & f_minus) && !(f->flags & f_zero))
		repeat_char(inst, ' ', f->width - len);
	if (f->flags & f_space)
		write_buf(inst, " ", 1);
	if (i.d < 0 || f->flags & f_plus)
		write_buf(inst, i.d < 0 ? "-" : "+", 1);
	if (f->width > len && !(f->flags & f_minus) && !!(f->flags & f_zero))
		repeat_char(inst, '0', f->width - len);
	writeld(inst, f, &s_ipart, &s_dpart);
	if (f->width > len && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - len);
	return (0);
}
