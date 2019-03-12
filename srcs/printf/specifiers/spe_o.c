/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 13:46:25 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_o(t_arg i, t_printf *inst, t_format *fmt)
{
	t_int_str8	str;

	str = ft_uint_to_str8(downcast(fmt->sub_sp, i.i, TRUE));
	write_buf(inst, str.str, str.len);
	return (str.len);
}
