/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:01:06 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/15 19:09:01 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		abs_ld(long double a)
{
	return (a < 0 ? -a : a);
}

int		specifier_f(t_arg i, t_printf *inst, t_format *f)
{
	/*const intmax_t		ipart = (intmax_t)i.d;
	t_int_str	str;
	char	c;

	str = ft_uint_to_str(abs_uintmaxt(i.d));
	write_buf(inst, str.str, str.len);
	write_buf(inst, ".", 1);

	intmax_t mut_ab = ft_pow(10, 12);
	intmax_t after_point_flt = (intmax_t)(i.d * mut_ab);
	intmax_t multiplier = ft_pow(10, (12 - 1));
	for(int xy=0; xy<12; xy++)
    {
        intmax_t muted = (after_point_flt / multiplier);
		//printf("%d\n",muted);
        muted = muted % 10;
		c = ((muted) + '0');
        write_buf(inst, &c, 1);
        multiplier /= 10;
    }*/
    uintmax_t d = (long double)(abs_ld(i.d) - abs_uintmaxt(i.d)) * ft_pow(10, f->precision);
    printf ("%d %d\n", abs_uintmaxt(i.d), d);
    return (0);
}
