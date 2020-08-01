/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by fford             #+#    #+#             */
/*   Updated: 2020/03/05 17:41:45 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		pd(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ((p > w && w > l) || (p > l && l > w) || (w == p && p > l)\
		|| (p > w && w == l))
	{
		p -= l;
		print_sign(spec, flag);
		while (p--)
			ft_putchar_bytes('0', spec);
		if (flag->num)
			ft_print_num(spec, flag->num, 10, 97);
		return (1);
	}
	return (0);
}

int		wpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len;
		if (flag->zero)
			print_sign(spec, flag);
		if (!flag->minus)
			print_width(spec, flag);
		if (!flag->zero)
			print_sign(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int		wd_and_dw(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if (((w > l && l > p) || (w > p && p == l)))
	{
		flag->width -= l;
		if (flag->zero)
			print_sign(spec, flag);
		if (!flag->minus)
			print_width(spec, flag);
		if (!flag->zero)
			print_sign(spec, flag);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int		d(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if ((l > w && w > p) || (l > p && p > w) || (w == l && l > p) || \
		(w == l && l == p) || (p == l && l > w) || (l > w && w == p))
	{
		print_sign(spec, flag);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		return (1);
	}
	return (0);
}

void	print_d(t_spec *spec, t_flag *flag)
{
	make_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->sign || flag->plus || flag->space)
		flag->width--;
	if (flag->precision > 0)
		flag->zero = 0;
	if (!pd(spec, flag))
		if (!d(spec, flag))
			if (!wd_and_dw(spec, flag))
				wpd_and_pdw(spec, flag);
}
