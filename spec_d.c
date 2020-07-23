/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:41:45 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void make_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (signed char)va_arg(spec->ap, int);
	else if (flag->h)
		num = (short)va_arg(spec->ap, int);
	else if (flag->l)
		num = (long)va_arg(spec->ap, long int);
	else if (flag->ll)
		num = (long long)va_arg(spec->ap, long long int);
	else
		num = (int)va_arg(spec->ap, int);
	if (num < 0 && ++flag->sign)
		flag->num = (unsigned long)num * -1;
	else
		flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 10);
	if (flag->num == 0 && flag->dot)
	{
		flag->precision++;
		flag->width++;
	}
}	

int	ft_len_number(unsigned long num, unsigned rang)
{
	int	res;

	res = 1;
	while (num >= rang)
	{
		num /= rang;
		res++;
	}
	return (res);
}

void		ft_print_num(t_spec *spec, unsigned long n, unsigned rang, char c)
{
	if (n >= rang)
		ft_print_num(spec, n / rang, rang, c);
	n = n % rang;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_bytes((char)n, spec);
}

void				print_sign(t_spec *spec, t_flag *flag)
{
	if (flag->plus && !flag->sign)
		ft_putchar_bytes('+', spec );
	if (flag->sign)
		ft_putchar_bytes('-', spec);
	else if (flag->space && !flag->plus)
		ft_putchar_bytes(' ', spec);
}

int pd(t_spec *spec, t_flag *flag)//done
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


int wpd_and_pdw(t_spec *spec, t_flag *flag)//done
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
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}
 

int wd_and_dw(t_spec *spec, t_flag *flag)//done
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
		if (!flag->minus)//wd
			print_width(spec, flag);
		if (!flag->zero)
			print_sign(spec, flag);
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		if (flag->minus)//dw
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int d(t_spec *spec, t_flag *flag)//done
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
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 10, 97);
		return (1);
	}
	return (0);
}


int			print_d(t_spec *spec, t_flag *flag)
{
	make_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->sign || flag->plus || flag->space)
		flag->width--;
	if (flag->precision > 0)
		flag->zero = 0;

	if (pd(spec, flag))
		return (1);
	else if (d(spec, flag))
		return (1);
	else if (wd_and_dw(spec, flag))
		return (1);
	else if (wpd_and_pdw(spec, flag))
		return (1);
	return (0);
}