/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:32:42 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 15:00:56 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	repeat_char(t_printf *inst, char c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		write_buf(inst, &c, 1);
}

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
