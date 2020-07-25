/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:42:29 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		opd(t_spec *spec, t_flag *flag)
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
		while (p--)
			ft_putchar_bytes('0', spec);
		if (flag->hash && flag->precision < 1)
			ft_putchar_bytes('0', spec);
		ft_print_num(spec, flag->num, 8, 97);
		return (1);
	}
	return (0);
}

int		owpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len;
		if (!flag->minus)
			print_width(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->hash && flag->precision < 1)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 8, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int		owd_and_dw(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if (((w > l && l > p) || (w > p && p == l)))
	{
		if (flag->num)
			flag->width -= l;
		if (!flag->minus)
			print_width(spec, flag);
		if (flag->hash)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 8, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int		od(t_spec *spec, t_flag *flag)
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
		if (flag->hash)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 8, 97);
		return (1);
	}
	return (0);
}

int		print_o(t_spec *spec, t_flag *flag)
{
	omake_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->precision > 0)
		flag->zero = 0;
	if (flag->num == 0 && !flag->dot)
		flag->hash = 0;
	if (opd(spec, flag))
		return (1);
	else if (od(spec, flag))
		return (1);
	else if (owd_and_dw(spec, flag))
		return (1);
	else if (owpd_and_pdw(spec, flag))
		return (1);
	return (0);
}
