/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 19:29:25 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width(t_spec *spec, t_flag *flag)
{
	while (flag->width--)
	{
		if (flag->zero && !flag->minus)
			ft_putchar_bytes('0', spec);
		else
			ft_putchar_bytes(' ', spec);
	}
}

int		print_s(t_spec *spec, t_flag *flag)
{
	char	*str;
	char	*out;
	int		len;

	if (!(str = (char *)va_arg(spec->ap, char*)))
		out = ft_strdup("(null)");
	else
		out = ft_strdup(str);
	len = ft_strlen(out);
	if (len > flag->precision && flag->dot)
	{
		len = flag->precision;
		out[flag->precision] = '\0';
	}
	if (flag->minus)
		write(1, out, len);
	if (flag->width > len)
		flag->width -= len;
	else
		flag->width = 0;
	spec->bytes += len;
	print_width(spec, flag);
	if (!flag->minus)
		write(1, out, len);
	free(out);
	return (0);
}

void	print_lc(char c)
{
	c = (wchar_t)c;
	write(1, &c, 1);
}

int		print_c(t_spec *spec, t_flag *flag)
{
	char	c;

	c = (char)va_arg(spec->ap, char*);
	if (flag->width)
		flag->width--;
	if (flag->minus)
	{
		if (flag->l)
			print_lc(c);
		else
			ft_putchar_bytes(c, spec);
	}
	print_width(spec, flag);
	if (!flag->minus)
		ft_putchar_bytes(c, spec);
	return (0);
}
