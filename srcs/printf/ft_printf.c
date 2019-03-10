/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:34:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/07 16:45:01 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int		write_buf(t_printf *inst, const char *str, size_t len)
{
	if (inst->buff_pos + len >= PRINTF_BUFF)
	{
		write(1, inst->buffer, inst->buff_pos);
		ft_bzero(inst->buffer, PRINTF_BUFF);
		inst->buff_pos = 0;
	}
	ft_strncpy(inst->buffer + inst->buff_pos, str, len);
	inst->buff_pos += len;
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

int		specifier_di(size_t i, t_printf *inst, t_format *fmt)
{
	char	tab[20];
	size_t	len;
	int		j;

	len = numlen(i);
	printf("hey %ld\n", len);
	ft_bzero(tab, 20);
	j = len;
	while (--j > -1)
	{
		printf("d %c %ld\n", (i % 10) + '0', j);
		tab[j] = (i % 10) + '0';
		i /= 10;
	}
	write_buf(inst, tab, len);
	return (0);
}

int		compute_specifier(t_printf *inst, t_format *fmt)
{
	char	*c;

	if (!(c = ft_strchr("sSpdDiouxXcCfF", inst->format[inst->cursor])))
		return (-1);
//	printf("char %c\n", *c);
	g_spe[CHAR(*c)].fn((size_t)ft_abs(va_arg(inst->args, int)), inst, fmt);
//	printf("Where am i? %d %s\n", fmt->sub_sp, inst->format + inst->cursor);
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
	write(1, inst.buffer, inst.buff_pos);
	va_end(inst.args);
	return (0);
}
