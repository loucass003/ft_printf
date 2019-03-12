/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:18:37 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/12 15:56:00 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

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

typedef enum		e_types
{
	INT,
	UINT,
	LONG,
	LLONG,
	ULONG,
	ULLONG,
	PTR
}					t_types;

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
	size_t			precision;
	t_subsp			sub_sp;
	char			specifier;
	t_bool			negative;
	t_types			varg_type;
}					t_format;

typedef struct		s_specifier
{
	int				(*fn)();
}					t_specifier;

typedef union		u_arg
{
	uintmax_t		i;
	long double		d;
	void			*p;
}					t_arg;

int					specifier_d(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_o(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_u(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_x(t_arg i, t_printf *inst, t_format *fmt);

int					compute_specifier(t_printf *inst, t_format *fmt);
int					compute_formatter(t_printf *inst);
int					write_buf(t_printf *inst, const char *str, size_t len);

void				repeat_char(t_printf *inst, char c, size_t len);
int					get_flag(char c);
uintmax_t			downcast(t_subsp sp, uintmax_t nb, t_bool unsign);

int					ft_printf(const char *format, ...);

# define CHAR(x) (x - 'A')

static t_specifier	g_spe[] =
{
	[CHAR('d')] = (t_specifier){ specifier_d },
	[CHAR('i')] = (t_specifier){ specifier_d },
	[CHAR('o')] = (t_specifier){ specifier_o },
	[CHAR('u')] = (t_specifier){ specifier_u },
	[CHAR('x')] = (t_specifier){ specifier_x },
	[CHAR('X')] = (t_specifier){ specifier_x }
};

#endif
