/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 03:21:21 by fford             #+#    #+#             */
/*   Updated: 2020/07/25 03:26:29 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	perm_s_o_b(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'x')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0x", spec);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 97);
	}
	if (spec->format[spec->i] == 'X')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0X", spec);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 65);
	}
}

int		xpd(t_spec *spec, t_flag *flag)
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
		if (flag->num)
			flag->precision -= l;
		perm_s_o_b(spec, flag);
		return (1);
	}
	return (0);
}

int		xwpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		if (flag->num)
			flag->precision -= flag->len;
		if (flag->hash && flag->num)
			flag->width -= 2;
		if (!flag->minus)
			print_width(spec, flag);
		perm_s_o_b(spec, flag);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

void	wid_s_o_b(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'x')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0x", spec);
		if (flag->zero)
			print_width(spec, flag);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 97);
	}
	if (spec->format[spec->i] == 'X')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0X", spec);
		if (flag->zero)
			print_width(spec, flag);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 65);
	}
}

int		xwd_and_dw(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if (((w > l && l > p) || (w > p && p == l)))
	{
		if (flag->num || (!flag->dot && !flag->num))
			flag->width -= l;
		if (flag->hash && flag->num)
			flag->width -= 2;
		if (!flag->minus && !flag->zero)
			print_width(spec, flag);
		wid_s_o_b(spec, flag);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}
