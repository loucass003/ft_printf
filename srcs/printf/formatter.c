/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:39:19 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/21 16:16:35 by llelievr         ###   ########.fr       */
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
	else if (inst->format[inst->cursor] == 'j' && ++inst->cursor)
		fmt->sub_sp = sp_j;
	else if (inst->format[inst->cursor] == 'z' && ++inst->cursor)
		fmt->sub_sp = sp_z;
	else if (inst->format[inst->cursor] == 'L' && ++inst->cursor)
		fmt->sub_sp = sp_L;
	return (compute_specifier(inst, fmt));
}

int		compute_precision(t_printf *inst, t_format *fmt)
{
	if (inst->format[inst->cursor] == '.'
		&& inst->cursor + 1 < inst->format_len)
	{
		inst->cursor++;
		fmt->precision = 0;
		while (inst->format[inst->cursor]
			&& ft_isdigit(inst->format[inst->cursor]))
			fmt->precision = fmt->precision * 10
				+ inst->format[inst->cursor++] - '0';
		if (inst->format[inst->cursor] == '*' && ++inst->cursor)
		{
			fmt->precision = va_arg(inst->args, int);
			if ((int)fmt->precision < 0)
				fmt->precision = -1;
		}
	}
	return (compute_sub_spe(inst, fmt));
}

int		compute_width(t_printf *inst, t_format *fmt)
{
	while (inst->format[inst->cursor] && ft_isdigit(inst->format[inst->cursor]))
		fmt->width = fmt->width * 10 + inst->format[inst->cursor++] - '0';
	if (inst->format[inst->cursor] == '*' && ++inst->cursor)
	{
		fmt->width = va_arg(inst->args, int);
		if ((int)fmt->width < 0)
		{
			fmt->width *= -1;
			fmt->flags |= f_minus;
		}
	}
	return (compute_precision(inst, fmt));
}

int		compute_flag(t_printf *inst, t_format *fmt)
{
	t_flag		flag;

	while (inst->format[inst->cursor]
		&& (flag = get_flag(inst->format[inst->cursor])) > 0)
	{
		fmt->flags |= flag;
		inst->cursor++;
	}
	if (fmt->flags & f_space && fmt->flags & f_plus)
		fmt->flags ^= f_space;
	if (fmt->flags & f_minus && fmt->flags & f_zero)
		fmt->flags ^= f_zero;
	return (compute_width(inst, fmt));
}

int		compute_formatter(t_printf *inst)
{
	t_format	fmt;

	fmt = (t_format){ .precision = -1 };
	if (inst->cursor + 1 < inst->format_len)
	{
		inst->cursor++;
		return (compute_flag(inst, &fmt));
	}
	inst->cursor++;
	return (0);
}
