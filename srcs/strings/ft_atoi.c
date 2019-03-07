/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:28:50 by llelievr          #+#    #+#             */
/*   Updated: 2019/03/07 15:02:45 by llelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned long	out;
	char			signe;

	out = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	if (!(*str >= '0' && *str <= '9') && (*str != '-' && *str != '+'))
		return (0);
	if (*str == '-' || *str == '+')
		signe = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		out = out * 10 + (*str++) - '0';
	return (out * signe);
}
