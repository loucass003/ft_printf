/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:40:45 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/14 12:27:59 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	get_arg(t_printf *inst, t_format *fmt)
{
	t_arg	arg;

	arg.i = 0;
	if (fmt->varg_type == PTR)
		arg.p = va_arg(inst->args, void *);
	if (fmt->varg_type == INT)
		arg.i = va_arg(inst->args, int);
	else if (fmt->varg_type == UINT)
		arg.i = va_arg(inst->args, unsigned int);
	else if (fmt->varg_type == LONG)
		arg.i = va_arg(inst->args, long);
	else if (fmt->varg_type == ULONG)
		arg.i = va_arg(inst->args, unsigned long);
	else if (fmt->varg_type == LLONG)
		arg.i = va_arg(inst->args, long long);
	else if (fmt->varg_type == ULLONG)
		arg.i = va_arg(inst->args, unsigned long long);
	return (arg);
}

t_types	subsp_arg_di(t_format *fmt, t_specifier spe)
{
	if (fmt->sub_sp == sp_l || fmt->sub_sp == sp_ll)
		return (fmt->sub_sp == sp_l ? LONG : LLONG);
	return (spe.default_arg);
}

t_types	subsp_arg_oux(t_format *fmt, t_specifier spe)
{
	if (fmt->sub_sp == sp_l || fmt->sub_sp == sp_ll)
		return (fmt->sub_sp == sp_l ? ULONG : ULLONG);
	return (spe.default_arg);
}

t_types	default_arg(t_format *fmt, t_specifier spe)
{
	return (spe.default_arg);
}

int		compute_specifier(t_printf *inst, t_format *fmt)
{
	char		*c;
	t_arg		arg;
	t_specifier	spe;

	if (!(c = ft_strchr("spdiouxXcfF", inst->format[inst->cursor])))
		return (-1);
	fmt->specifier = *c;
	spe = g_spe[CHAR(fmt->specifier)];
	if ((fmt->varg_type = spe.get_arg(fmt, spe)) == TYPES_NONE)
		return (-1);
	arg = get_arg(inst, fmt);
	g_spe[CHAR(fmt->specifier)].fn(arg, inst, fmt);
	return (0);
}
