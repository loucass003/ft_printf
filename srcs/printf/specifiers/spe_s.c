/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:35:05 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/13 16:57:11 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_s(t_arg i, t_printf *inst, t_format *f)
{
	char		*str;
	uintmax_t	tlen;
	size_t		slen;

	if (f->precision == 0)
		return (0);
	str = (char *)i.p;
	str = !i.p ? "(null)" : i.p;
	slen = ft_strlen(str);
	if (f->precision == -1 || !i.p)
		f->precision = !i.p ? 6 : slen;
	slen = mint(f->precision, slen);
	if (f->width > slen && !(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - slen);
	write_buf(inst, str, slen);
	if (f->width > slen && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - slen);
	return (0);
}
