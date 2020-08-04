/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 03:53:33 by fford             #+#    #+#             */
/*   Updated: 2020/07/25 03:56:29 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	make_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (signed char)va_arg(spec->ap, int);
	else if (flag->h)
		num = (short)va_arg(spec->ap, int);
	else if (flag->l)
		num = (unsigned long int)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long);
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

void	omake_4thflag(t_spec *spec, t_flag *flag)
{
	unsigned long	num;

	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long int)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 8);
	if (flag->hash && flag->precision < 1)
		flag->width--;
}

void	umake_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long int)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 10);
}

void	xmake_4thflag(t_spec *spec, t_flag *flag)
{
	unsigned long	num;

	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long int)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 16);
}

void	bmake_4thflag(t_spec *spec, t_flag *flag)
{
	unsigned long	num;

	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long int)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 2);
	if (flag->hash && flag->precision < 1)
		flag->width--;
}
