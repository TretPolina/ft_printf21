/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:22:24 by fford             #+#    #+#             */
/*   Updated: 2020/03/06 18:35:17 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	parse_star(t_spec *spec, t_flag *flag)
{
	int val;

	if (spec->format[spec->i] == '*' && ++spec->i)
	{
		flag->star = 1;
		if ((val = (int)va_arg(spec->ap, int)))
		{
			if (val < 0 && flag->dot)
				flag->dot = 0;
			else if (val < 0 && flag->dot == 0)
			{
				flag->minus = 1;
				flag->width = FT_ABS(val);
			}
			else
			{
				if (flag->dot)
					flag->precision = val;
				else
					flag->width = val;
			}
		}
		else
			flag->zero = 1;
	}
}

void	parse_number(t_spec *spec, t_flag *flag, int *res)
{
	if (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0' &&
		(!*res || flag->star))
	{
		*res = 0;
		while (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0')
		{
			*res *= 10;
			*res += spec->format[spec->i] - '0';
			spec->i++;
		}
	}
}
