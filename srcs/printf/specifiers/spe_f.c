/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:01:06 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 16:31:08 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_types		subsp_arg_f(t_format *fmt, t_specifier spe)
{
	if (fmt->sub_sp == sp_L)
		return (LDOUBLE);
	return (spe.default_arg);
}

void		computeld(t_format *f, t_str_float *s,
	long double d)
{
	if (f->precision == -1)
		f->precision = 6;
	s->v.v = d;
	d += (4.5 * powld(10, -f->precision - 1)) * (s->v.parts.sign ? -1 : 1);
	s->ipart = abs_uintmaxt(d);
	s->dpart = (long double)(abs_ld(d) - s->ipart)
		* powld(10, f->precision == 0 ? 1 : f->precision);
	s->s_ipart = ft_uint_to_str(s->ipart);
	s->s_dpart = ft_uint_to_str(s->dpart);
}

void		writeinf(t_printf *inst, t_format *f, t_str_float *s)
{
	uintmax_t	len;

	len = 3 + (s->v.parts.sign || f->flags & f_plus);
	if (f->width > len && !(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - len);
	if (s->v.parts.sign || f->flags & f_plus)
		write_buf(inst, s->v.v < 0 ? "-" : "+", 1);
	if (s->v.v != s->v.v)
		write_buf(inst, "nan", 3);
	else
		write_buf(inst, "inf", 3);
	if (f->width > len && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - len);
	s->s_ipart.len = 3;
	s->s_dpart.len = 0;
}

void		writeld(t_printf *inst, t_format *f, t_str_float *s)
{
	write_buf(inst, s->s_ipart.str, s->s_ipart.len);
	if (f->precision == 0 && !(f->flags & f_hash))
		return ;
	write_buf(inst, ".", 1);
	if ((f->precision <= 1 && s->s_dpart.len == 1
		&& s->s_dpart.str[0] == '0') || f->precision == 0)
		return ;
	write_buf(inst, s->s_dpart.str, s->s_dpart.len);
	if (f->precision > s->s_dpart.len)
		repeat_char(inst, '0', f->precision - s->s_dpart.len);
}

int			specifier_f(t_arg i, t_printf *inst, t_format *f)
{
	t_str_float	s;
	uintmax_t	len;

	computeld(f, &s, i.d);
	if (s.v.v != s.v.v || s.v.v == s.v.v + 1)
	{
		writeinf(inst, f, &s);
		return (0);
	}
	if (s.v.parts.sign && (f->flags & f_space))
		f->flags ^= f_space;
	len = s.s_ipart.len + s.s_dpart.len + (f->precision - s.s_dpart.len)
	+ (!!(f->flags & f_plus) || s.v.parts.sign) + 1 + !!(f->flags & f_space);
	if (f->width > len && !(f->flags & f_minus) && !(f->flags & f_zero))
		repeat_char(inst, ' ', f->width - len);
	if (f->flags & f_space)
		write_buf(inst, " ", 1);
	if (s.v.parts.sign || f->flags & f_plus)
		write_buf(inst, s.v.parts.sign ? "-" : "+", 1);
	if (f->width > len && !(f->flags & f_minus) && !!(f->flags & f_zero))
		repeat_char(inst, '0', f->width - len);
	writeld(inst, f, &s);
	if (f->width > len && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - len);
	return (0);
}
