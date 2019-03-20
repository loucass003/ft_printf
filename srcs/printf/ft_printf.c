/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:34:00 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/20 17:16:37 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_printf	inst;
	char		*c;

	if (!format)
		return (-1);
	inst = (t_printf){ .format = format, .format_len = ft_strlen(format),
		.cursor = 0 };
	va_start(inst.args, format);
	/*while (++inst.cursor < inst.format_len)
	{
		if (format[inst.cursor] == '%')
		{
			if (compute_formatter(&inst) == -1)
			{
				inst.writed_len = -1;
				break ;
			}
		}
		else
			write_buf(&inst, format + inst.cursor, 1);
	}*/
	c = (char *)inst.format;
	while ((c = ft_strchr(c, '%')))
	{
		write_buf(&inst, inst.format + inst.cursor, c - (inst.format + inst.cursor));
		inst.cursor += c - (inst.format + inst.cursor);
		if (compute_formatter(&inst) == -1)
		{
			inst.writed_len = -1;
			break ;
		}
		c = (char *)inst.format + inst.cursor;
	}
	write_buf(&inst, inst.format + inst.cursor, inst.format_len - inst.cursor);
	write(1, inst.buffer, inst.buff_pos);
	va_end(inst.args);
	return (inst.writed_len);
}
