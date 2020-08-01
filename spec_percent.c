/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:23:11 by fford             #+#    #+#             */
/*   Updated: 2020/07/14 19:29:25 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_percent(t_spec *spec, t_flag *flag)
{
	if (flag->width)
		flag->width--;
	if (flag->minus)
	{
		ft_putchar_bytes('%', spec);
		while (flag->width--)
			ft_putchar_bytes(' ', spec);
	}
	else
	{
		while (flag->width--)
		{
			if (flag->zero)
				ft_putchar_bytes('0', spec);
			else
				ft_putchar_bytes(' ', spec);
		}
		ft_putchar_bytes('%', spec);
	}
}
