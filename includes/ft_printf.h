/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:29:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 18:55:44 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# define FT_ABS(X) ((X) < 0 ? - (X) : (X))
# define TYPE "cCdioOuUxXfFeEgGsS"
#include <stdarg.h>
#include <stdio.h>//убрать потом
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_flag
{
	int		plus;
	int		minus;
	int		hash;
	int		space;
	int		zero;
		
	int		star;
	int		width;
	int		dot;
	int		precision;
	
	int		l;
	int		ll;
	int		L;
	int		h;
	int		hh;
	
	int		sign;
	unsigned long		num;
	int		len;
	char	type;
}					t_flag;

typedef struct		s_spec
{
	int		i;
	char	*format;
	int		bytes;
	va_list	ap;
}					t_spec;

int			ft_printf(const char *format, ...);
void    	first_flag(t_spec *spec, t_flag *flag);
void    	second_flag(t_spec *spec, t_flag *flag);
void    	third_flag(t_spec *spec, t_flag *flag);
void    	fourth_flag(t_spec *spec, t_flag *flag);
int			print_spec(t_spec *spec, t_flag *flag);

int			print_c(t_spec *spec, t_flag *flag);
int			print_s(t_spec *spec, t_flag *flag);
int			print_q(t_spec *spec, t_flag *flag);
int			print_d(t_spec *spec, t_flag *flag);
int			print_u(t_spec *spec, t_flag *flag);
int			print_o(t_spec *spec, t_flag *flag);
int			print_percent(t_spec *spec, t_flag *flag);
/* int			print_d(t_spec *spec);
int			print_e(t_spec *spec);
int			print_g(t_spec *spec);
int			print_p(t_spec *spec); */
int			print_x(t_spec *spec, t_flag *flag);
//int			print_f(t_spec *spec);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *src);
int			ft_putchar_bytes(int c, t_spec *spec);
char		*ft_itoa_base(int value, int base, int size);
int			ft_atoi(const char *str);
void		ft_putstr_bytes(char const *s, t_spec *spec);
void		parse_star(t_spec *spec, t_flag *flag);
void		parse_number(t_spec *spec, t_flag *flag, int *res);
/**************************/
void 		make_4thflag(t_spec *spec, t_flag *flag);
int			ft_len_number(unsigned long num, unsigned rang);
void		ft_print_num(t_spec *spec, unsigned long n, unsigned rang, char c);
void		print_width(t_spec *spec, t_flag *flag);
int 		pd(t_spec *spec, t_flag *flag);
int 		wpd(t_spec *spec, t_flag *flag);

void 		umake_4thflag(t_spec *spec, t_flag *flag);
void 		omake_4thflag(t_spec *spec, t_flag *flag);

#endif
