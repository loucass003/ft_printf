/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:34:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/11 18:23:43 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int		write_buf(t_printf *inst, const char *str, size_t len)
{
	while (1)
	{
		if (len < PRINTF_BUFF - inst->buff_pos)
		{
			ft_memcpy(inst->buffer + inst->buff_pos, str,
				len);
			inst->buff_pos += len;
			break ;
		}
		else
		{
			ft_memcpy(inst->buffer + inst->buff_pos, str,
				PRINTF_BUFF - inst->buff_pos);
			write(1, inst->buffer, PRINTF_BUFF);
			len -= PRINTF_BUFF - inst->buff_pos;
			str += PRINTF_BUFF - inst->buff_pos;
			inst->buff_pos = 0;
		}
	}
	return (0);
}

int		get_flag(char c)
{
	if (c == '+')
		return (f_plus);
	if (c == '-')
		return (f_minus);
	if (c == '0')
		return (f_zero);
	if (c == '#')
		return (f_hash);
	if (c == ' ')
		return (f_space);
	return (0);
}

uintmax_t	downcast(t_subsp sp, uintmax_t nb, t_bool unsign)
{
	if (unsign)
	{
		if (sp == sp_hh)
			return ((unsigned char)nb);
		if (sp == sp_h)
			return ((unsigned short)nb);
	}
	else
	{
		if (sp == sp_hh)
			return ((char)nb);
		if (sp == sp_h)
			return ((short)nb);
	}
	return (nb);
}

int		numlen(ssize_t i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		j++;
		i /= 10;
	}
	return (j);
}

int		specifier_d(t_arg i, t_printf *inst, t_format *fmt)
{
	t_int_str	str;

	str = ft_uint_to_str(downcast(fmt->sub_sp, i.i, FALSE));
	write_buf(inst, str.str, str.len);
	return (0);
}

t_arg	get_arg(t_printf *inst, t_format *fmt)
{
	t_arg	arg;

	arg.i = 0;
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		arg.i = va_arg(inst->args, int);
	return (arg);
}

int		compute_specifier(t_printf *inst, t_format *fmt)
{
	char	*c;
	t_arg	arg;

	if (!(c = ft_strchr("sSpdDiouxXcCfF", inst->format[inst->cursor])))
		return (-1);
	fmt->specifier = *c;
	arg = get_arg(inst, fmt);
	g_spe[CHAR(fmt->specifier)].fn(arg, inst, fmt);
	return (0);
}

int		compute_sub_spe(t_printf *inst, t_format *fmt)
{
	if (inst->format[inst->cursor] == 'h')
	{
		fmt->sub_sp = sp_h;
		if (inst->cursor + 1 < inst->format_len && inst->format[inst->cursor + 1] == 'h' && ++inst->cursor)
			fmt->sub_sp = sp_hh;
		inst->cursor++;
	}
	else if (inst->format[inst->cursor] == 'l')
	{
		fmt->sub_sp = sp_l;
		if (inst->cursor + 1 < inst->format_len && inst->format[inst->cursor + 1] == 'l' && ++inst->cursor)
			fmt->sub_sp = sp_ll;
		inst->cursor++;
	}
	return (compute_specifier(inst, fmt));
}

int		compute_precision(t_printf *inst, t_format *fmt)
{
	if (inst->format[inst->cursor] == '.' && inst->cursor + 1 < inst->format_len)
	{
		inst->cursor++;
		fmt->precision = 0;
		while (inst->format[inst->cursor] >= '0' && inst->format[inst->cursor] <= '9')
			fmt->precision = fmt->precision * 10 + inst->format[inst->cursor++] - '0';
	}
	return (compute_sub_spe(inst, fmt));
}

int		compute_width(t_printf *inst, t_format *fmt)
{
	while (inst->format[inst->cursor] >= '0' && inst->format[inst->cursor] <= '9')
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

	fmt = (t_format){ .precision = -1 };
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

int		ft_printf(const char *format, ...)
{
	t_printf	inst;

	inst = (t_printf){ .format = format, .format_len = ft_strlen(format),
		.cursor = -1 };
	va_start(inst.args, format);
	while (++inst.cursor < inst.format_len)
	{
		if (format[inst.cursor] == '%')
		{
			if (compute_formatter(&inst) == -1)
				break ;
		}
		else
			write_buf(&inst, format + inst.cursor, 1);
	}
	// char	*c;
	// while ((c = ft_strchr(inst.format + inst.cursor, '%')) != NULL)
	// {
	// 	if (c - inst.format > 0)
	// 		write_buf(&inst, format + inst.cursor, c - inst.format);
	// 	inst.cursor += c - inst.format;
	// 	if (compute_formatter(&inst) == -1)
	// 		break ;
	// }
	// if (inst.cursor < inst.format_len)
	// 	write_buf(&inst, inst.format + inst.cursor, inst.format_len - inst.cursor);
	write(1, inst.buffer, inst.buff_pos);
	va_end(inst.args);
	return (0);
}
