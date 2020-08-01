/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:29:44 by fford             #+#    #+#             */
/*   Updated: 2020/03/06 17:54:05 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	flags(t_spec *spec, t_flag *flag)
{
	first_flag(spec, flag);
	second_flag(spec, flag);
	third_flag(spec, flag);
	fourth_flag(spec, flag);
	print_spec(spec, flag);
}

int		parse(t_spec *spec, t_flag *flag)
{
	spec->i = 0;
	spec->bytes = 0;
	while (spec->format[spec->i] != '\0')
	{
		if (spec->format[spec->i] == '%')
		{
			spec->i++;
			flags(spec, flag);
		}
		else
		{
			ft_putchar_bytes(spec->format[spec->i], spec);
			spec->i++;
		}
	}
	return (spec->bytes);
}

int		ft_printf(const char *format, ...)
{
	t_spec		spec;
	t_flag		flag;

	va_start(spec.ap, format);
	spec.format = ft_strdup(format);
	parse(&spec, &flag);
	va_end(spec.ap);
	free(spec.format);
	return (spec.bytes);
}
