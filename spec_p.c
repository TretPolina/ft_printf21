/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:23:11 by fford             #+#    #+#             */
/*   Updated: 2020/07/26 19:29:25 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	keep_arg(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = (long long)va_arg(spec->ap, long long int);
	flag->num = num;
	flag->len = ft_len_number(flag->num, 16);
	flag->width -= 2;
}

int		wtl(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->len)
	{
		flag->width -= flag->len;
		if (!flag->minus && !flag->zero)
			print_width(spec, flag);
		ft_putstr_bytes("0x", spec);
		if (flag->zero)
			print_width(spec, flag);
		ft_print_num(spec, flag->num, 16, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int		ltw(t_spec *spec, t_flag *flag)
{
	int w;
	int l;

	l = flag->len;
	w = flag->width;
	if ((l > w) || (w == l))
	{
		ft_putstr_bytes("0x", spec);
		ft_print_num(spec, flag->num, 16, 97);
	}
	return (0);
}

void	print_p(t_spec *spec, t_flag *flag)
{
	keep_arg(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	ltw(spec, flag);
	wtl(spec, flag);

}