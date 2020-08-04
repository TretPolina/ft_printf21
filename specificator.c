/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:22:24 by fford             #+#    #+#             */
/*   Updated: 2020/03/06 18:35:17 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	def_types(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'c')
		print_c(spec, flag);
	if (spec->format[spec->i] == 's')
		print_s(spec, flag);
	if (spec->format[spec->i] == 'p')
		print_p(spec, flag);
	if (spec->format[spec->i] == 'd' || spec->format[spec->i] == 'i')
		print_d(spec, flag);
	if (spec->format[spec->i] == 'u')
		print_u(spec, flag);
	if (spec->format[spec->i] == 'o')
		print_o(spec, flag);
	if (spec->format[spec->i] == 'x' || spec->format[spec->i] == 'X')
		print_x(spec, flag);
	if (spec->format[spec->i] == 'f')
		print_f(spec, flag);
	if (spec->format[spec->i] == '%')
		print_percent(spec, flag);
	if (spec->format[spec->i] == 'b')
		print_b(spec, flag);
	return (0);
}

int	print_spec(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'c' || spec->format[spec->i] == 's' ||
		spec->format[spec->i] == 'p' || spec->format[spec->i] == 'd' ||
		spec->format[spec->i] == 'i' || spec->format[spec->i] == 'o' ||
		spec->format[spec->i] == 'u' || spec->format[spec->i] == 'f' ||
		spec->format[spec->i] == 'x' || spec->format[spec->i] == 'X' ||
		spec->format[spec->i] == '%' || spec->format[spec->i] == 'b')
	{
		def_types(spec, flag);
		spec->i++;
	}
	return (0);
}
