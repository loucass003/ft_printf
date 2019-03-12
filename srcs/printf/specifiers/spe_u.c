/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:04:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 13:50:21 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		specifier_u(t_arg i, t_printf *inst, t_format *fmt)
{
	t_int_str	str;

	str = ft_uint_to_str(downcast(fmt->sub_sp, i.i, TRUE));
	write_buf(inst, str.str, str.len);
	return (str.len);
}
