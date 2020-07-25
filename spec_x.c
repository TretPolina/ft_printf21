/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:23:11 by fford             #+#    #+#             */
/*   Updated: 2020/07/19 19:29:25 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	xmake_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	if (num < 0 && ++flag->sign)
		flag->num = (unsigned long)num * -1;
	else
		flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 16);
}

void	small_or_big(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'x')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0x", spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 97);
	}
	if (spec->format[spec->i] == 'X')
	{
		if (flag->hash && flag->num)
			ft_putstr_bytes("0X", spec);
		if (flag->num || !flag->dot)
			ft_print_num(spec, flag->num, 16, 65);
	}
}

int		xd(t_spec *spec, t_flag *flag)
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
		small_or_big(spec, flag);
		return (1);
	}
	return (0);
}

int		print_x(t_spec *spec, t_flag *flag)
{
	xmake_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->dot)
		flag->zero = 0;
	if (flag->num == 0 && !flag->dot)
		flag->hash = 0;
	if (xpd(spec, flag))
		return (1);
	else if (xd(spec, flag))
		return (1);
	else if (xwd_and_dw(spec, flag))
		return (1);
	else if (xwpd_and_pdw(spec, flag))
		return (1);
	return (0);
}
