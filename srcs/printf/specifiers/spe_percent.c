/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:43:32 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 16:18:53 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_percent(t_arg i, t_printf *inst, t_format *f)
{
	(void)i;
	if (f->width > 1 && !(f->flags & f_minus))
		repeat_char(inst, f->flags & f_zero ? '0' : ' ', f->width - 1);
	write_buf(inst, "%", 1);
	if (f->width > 1 && !!(f->flags & f_minus))
		repeat_char(inst, ' ', f->width - 1);
	return (0);
}
