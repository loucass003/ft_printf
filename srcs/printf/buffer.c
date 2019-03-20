/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:32:42 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/20 17:18:44 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	repeat_char(t_printf *inst, char c, intmax_t len)
{
	char		buff[8];

	ft_memset(buff, c, 8);
	while (len > 8)
	{
		write_buf(inst, buff, 8);
		len -= 8;
	}
	write_buf(inst, buff, len);
}

int		write_buf(t_printf *inst, const char *str, intmax_t len)
{
	if (len <= 0)
		return (0);
	inst->writed_len += len;
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
