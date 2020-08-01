/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:38:54 by fford             #+#    #+#             */
/*   Updated: 2020/07/27 19:29:39 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

double	ft_power(double n, int pow)
{
	return (pow ? n * ft_power(n, pow - 1) : 1);
}
/*
double	ft_power(double x, int y)
{
	double z;

	z = x;
	while (y > 1)
	{
		z = z * x;
		y--;
	}
	return (z);
}*/


void	ft_put_decimal(t_spec *spec, t_flag *flag, long decimal)
{
	flag->precision -= ft_len_number(decimal, 10);
	if (!decimal)
		flag->precision++;
	while (flag->precision-- > 0)
		ft_putchar_bytes('0', spec);
	if (decimal)
	{
		if (decimal >= 10)
			ft_put_decimal(spec, flag, decimal / 10);
		decimal %= 10;
		ft_putchar_bytes((char)(decimal + '0'), spec);
	}
}

void	put_secondary(t_spec *spec, t_flag *flag)
{
	if (flag->zero && !flag->minus)
	{
		print_sign(spec, flag);
		while (flag->width-- > 0)
			ft_putchar_bytes('0', spec);
	}
	else
	{
		if (!flag->minus)
		{
			while (flag->width-- > 0)
				ft_putchar_bytes(' ', spec);
		}
		print_sign(spec, flag);
	}
	ft_print_num(spec, flag->num, 10, 97);
	if (flag->hash || flag->precision)
		ft_putchar_bytes('.', spec);
	ft_put_decimal(spec, flag, flag->dec_num);
	while (flag->width-- > 0)
		ft_putchar_bytes(' ', spec);
}

void	print_f(t_spec *spec, t_flag *flag)
{
	double long		n;
	double long		dec_num;

	if (flag->bigl)
		n = (double long)va_arg(spec->ap, double long);
	else
		n = (double)va_arg(spec->ap, double);
	if (n < 0 && ++flag->sign)
		n *= -1;
	if (!flag->dot)
		flag->precision = 6;
	dec_num = (n - (long)n) * ft_power(10, flag->precision + 1);
	dec_num = ((long)dec_num % 10 > 4) ? dec_num / 10 + 1 : dec_num / 10;
	flag->num = (long)n + (long)(dec_num / ft_power(10, flag->precision));
	flag->dec_num = (long)dec_num % (long)ft_power(10, flag->precision);
	flag->len = ft_len_number(flag->num, 10);
	flag->width -= flag->len + flag->precision;
	if (flag->hash || flag->precision)
		flag->width--;
	if (flag->space || flag->plus || flag->sign)
		flag->width--;
	put_secondary(spec, flag);
}
