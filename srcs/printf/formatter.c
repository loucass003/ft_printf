/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:39:19 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 15:59:44 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		compute_sub_spe(t_printf *inst, t_format *fmt)
{
	if (inst->format[inst->cursor] == 'h')
	{
		fmt->sub_sp = sp_h;
		if (inst->cursor + 1 < inst->format_len
			&& inst->format[inst->cursor + 1] == 'h' && ++inst->cursor)
			fmt->sub_sp = sp_hh;
		inst->cursor++;
	}
	else if (inst->format[inst->cursor] == 'l')
	{
		fmt->sub_sp = sp_l;
		if (inst->cursor + 1 < inst->format_len
			&& inst->format[inst->cursor + 1] == 'l' && ++inst->cursor)
			fmt->sub_sp = sp_ll;
		inst->cursor++;
	}
	return (compute_specifier(inst, fmt));
}

int		compute_precision(t_printf *inst, t_format *fmt)
{
	if (inst->format[inst->cursor] == '.'
		&& inst->cursor + 1 < inst->format_len)
	{
		inst->cursor++;
		fmt->precision = 0;
		while (ft_isdigit(inst->format[inst->cursor]))
			fmt->precision = fmt->precision * 10
				+ inst->format[inst->cursor++] - '0';
	}
	return (compute_sub_spe(inst, fmt));
}

int		compute_width(t_printf *inst, t_format *fmt)
{
	while (ft_isdigit(inst->format[inst->cursor]))
		fmt->width = fmt->width * 10 + inst->format[inst->cursor++] - '0';
	return (compute_precision(inst, fmt));
}

int		compute_flag(t_printf *inst, t_format *fmt)
{
	t_flag		flag;

	while (inst->format[inst->cursor]
		&& (flag = get_flag(inst->format[inst->cursor])) > 0)
	{
		if (flag == 0)
		{
			fmt->flags = 0;
			break ;
		}
		fmt->flags |= flag;
		inst->cursor++;
	}
	if (fmt->flags & f_space && fmt->flags & f_plus)
		fmt->flags ^= f_space;
	return (compute_width(inst, fmt));
}

int		compute_formatter(t_printf *inst)
{
	t_format	fmt;

	fmt = (t_format){ .precision = 0 };
	if (inst->cursor + 1 < inst->format_len)
	{
		inst->cursor++;
		if (inst->format[inst->cursor] == '%')
		{
			write_buf(inst, inst->format + inst->cursor, 1);
			return (1);
		}
		return (compute_flag(inst, &fmt));
	}
	return (0);
}
