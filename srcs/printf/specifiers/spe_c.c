/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:10:42 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/13 16:24:09 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_c(t_arg i, t_printf *inst, t_format *f)
{
	char	c;

	c = (char)i.i;
	if (f->width > 1 && !(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - 1);
	write_buf(inst, &c, 1);
	if (f->width > 1 && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - 1);
	return (0);
}
