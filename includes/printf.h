/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:18:37 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/19 17:52:59 by llelievr         ###   ########.fr       */
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
	TYPES_NONE,
	INT,
	UINT,
	LONG,
	LLONG,
	ULONG,
	ULLONG,
	DOUBLE,
	LDOUBLE,
	PTR
}					t_types;

typedef struct		s_printf
{
	va_list			args;
	va_list			prev_arg;
	char			buffer[PRINTF_BUFF];
	intmax_t		buff_pos;
	const char		*format;
	intmax_t		cursor;
	intmax_t		format_len;
	uintmax_t		writed_len;
}					t_printf;

typedef struct		s_format
{
	uint8_t			flags;
	uintmax_t		width;
	intmax_t		precision;
	t_subsp			sub_sp;
	char			specifier;
	t_bool			negative;
	t_types			varg_type;
}					t_format;

typedef struct		s_specifier
{
	t_types			(*get_arg)();
	t_types			default_arg;
	int				(*fn)();
}					t_specifier;

typedef union		u_arg
{
	uintmax_t		i;
	long double		d;
	void			*p;
}					t_arg;

typedef union		u_float
{
	struct			s_parts
	{
		uint64_t	mantissa : 64;
		uint16_t	exponent : 15;
		uint8_t		sign : 1;
	}				parts;
	long double		v;
}					t_float;

typedef struct		s_str_float
{
	t_float			v;
	uintmax_t		ipart;
	uintmax_t		dpart;
	t_int_str		s_ipart;
	t_int_str		s_dpart;
}					t_str_float;

int					specifier_d(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_o(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_u(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_x(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_c(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_s(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_p(t_arg i, t_printf *inst, t_format *fmt);
int					specifier_f(t_arg i, t_printf *inst, t_format *fmt);

t_types				subsp_arg_di(t_format *f, t_specifier s);
t_types				subsp_arg_oux(t_format *f, t_specifier s);
t_types				default_arg(t_format *f, t_specifier s);

int					compute_specifier(t_printf *inst, t_format *fmt);
int					compute_formatter(t_printf *inst);
int					write_buf(t_printf *inst, const char *str, intmax_t len);

void				repeat_char(t_printf *inst, char c, intmax_t len);
int					get_flag(char c);
uintmax_t			downcast(t_subsp sp, uintmax_t nb, t_bool unsign);
uintmax_t			abs_uintmaxt(intmax_t n);
intmax_t			maxt(intmax_t a, intmax_t b);
intmax_t			mint(intmax_t a, intmax_t b);
long double			abs_ld(long double a);
long double			powld(long double n, int pow);

int					ft_printf(const char *format, ...);

# define CHAR(x) (x - 'A')

static t_specifier	g_spe[127] =
{
	[CHAR('d')] = (t_specifier){ subsp_arg_di, INT, specifier_d },
	[CHAR('i')] = (t_specifier){ subsp_arg_di, INT, specifier_d },
	[CHAR('o')] = (t_specifier){ subsp_arg_oux, UINT, specifier_o },
	[CHAR('u')] = (t_specifier){ subsp_arg_oux, UINT, specifier_u },
	[CHAR('x')] = (t_specifier){ subsp_arg_oux, UINT, specifier_x },
	[CHAR('X')] = (t_specifier){ subsp_arg_oux, UINT, specifier_x },
	[CHAR('c')] = (t_specifier){ default_arg, INT, specifier_c },
	[CHAR('s')] = (t_specifier){ default_arg, PTR, specifier_s },
	[CHAR('p')] = (t_specifier){ default_arg, PTR, specifier_p },
	[CHAR('f')] = (t_specifier){ default_arg, DOUBLE, specifier_f },
	[CHAR('F')] = (t_specifier){ default_arg, LDOUBLE, specifier_f }
};

#endif
