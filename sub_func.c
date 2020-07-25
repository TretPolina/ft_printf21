/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 03:34:30 by fford             #+#    #+#             */
/*   Updated: 2020/07/25 03:46:29 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_len_number(unsigned long num, unsigned rang)
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

void	ft_print_num(t_spec *spec, unsigned long n, unsigned rang, char c)
{
	if (n >= rang)
		ft_print_num(spec, n / rang, rang, c);
	n = n % rang;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_bytes((char)n, spec);
}

void	print_sign(t_spec *spec, t_flag *flag)
{
	if (flag->plus && !flag->sign)
		ft_putchar_bytes('+', spec);
	if (flag->sign)
		ft_putchar_bytes('-', spec);
	else if (flag->space && !flag->plus)
		ft_putchar_bytes(' ', spec);
}
