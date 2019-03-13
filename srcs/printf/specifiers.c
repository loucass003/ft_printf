/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:40:45 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/13 16:45:42 by llelievr         ###   ########.fr       */
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

int		get_arg_type(t_format *fmt)
{
	const char	*str = "diouxXcs";
	const int	i = ft_strchr(str, fmt->specifier) - str;

	if (i < 2)
	{
		if (fmt->sub_sp == sp_l || fmt->sub_sp == sp_ll)
			return (fmt->sub_sp == sp_l ? LONG : LLONG);
		return (INT);
	}
	if (i >= 2 && i < 6)
	{
		if (fmt->sub_sp == sp_l || fmt->sub_sp == sp_ll)
			return (fmt->sub_sp == sp_l ? ULONG : ULLONG);
		return (UINT);
	}
	if (i == 6)
		return (INT);
	if (i == 7)
		return (PTR);
	return (-1);
}

int		compute_specifier(t_printf *inst, t_format *fmt)
{
	char	*c;
	t_arg	arg;

	if (!(c = ft_strchr("sSpdDiouxXcCfF", inst->format[inst->cursor])))
		return (-1);
	fmt->specifier = *c;
	if ((fmt->varg_type = get_arg_type(fmt)) == -1)
		return (-1);
	arg = get_arg(inst, fmt);
	g_spe[CHAR(fmt->specifier)].fn(arg, inst, fmt);
	return (0);
}
