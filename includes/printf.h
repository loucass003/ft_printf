/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:18:37 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/07 17:28:11 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define PRINTF_BUFF 4

typedef enum		e_flag
{
	f_plus = 1 << 0,
	f_minus = 1 << 1,
	f_space = 1 << 2,
	f_zero = 1 << 3,
	f_hash = 1 << 4,
}					t_flag;

typedef enum		e_subsp
{
	sp_none,
	sp_hh,
	sp_h,
	sp_l,
	sp_ll
}					t_subsp;

typedef struct		s_printf
{
	va_list			args;
	va_list			prev_arg;
	char			buffer[PRINTF_BUFF];
	size_t			buff_pos;
	const char		*format;
	size_t			cursor;
	size_t			format_len;
}					t_printf;

typedef struct		s_format
{
	uint8_t			flags;
	size_t			width;
	long			precision;
	t_subsp			sub_sp;
	char			specifier;
}					t_format;

typedef struct		s_specifier
{
	int				(*fn)();
}					t_specifier;


int					ft_printf(const char *format, ...);

#endif
