/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:29:44 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 17:54:05 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void    flags(t_spec *spec, t_flag *flag)
{
    first_flag(spec, flag);
    second_flag(spec, flag);
    third_flag(spec, flag);
    fourth_flag(spec, flag);
	print_spec(spec, flag);
	/* printf("\n***************\n");
	printf("plus  %d\n", flag->plus);
	printf("minus %d\n", flag->minus);
	printf("hash  %d\n", flag->hash);
	printf("space %d\n", flag->space);
	printf("zero  %d", flag->zero);
	printf("\n---------------\n");
	printf("width %d", flag->width);
	printf("\n---------------\n");
	printf("precision %d", flag->precision);
	printf("\n---------------\n");
	printf("h  %d\n", flag->h);
	printf("hh %d\n", flag->hh);
	printf("l  %d\n", flag->l);
	printf("ll %d\n", flag->ll);
	printf("L  %d\n", flag->L);
	printf("flag NULL %d\n", flag->flag_null);
	printf("\n***************\n"); 
	*/
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
	if (!parse(&spec, &flag))
		return (-1);
	va_end(spec.ap);
	free(spec.format);
	//printf("\nbytes: %d", spec.bytes);
	return (spec.bytes);
}



/*
	записываем в spec.format format

	шаг 1:выводить сразу обычный текст 
	если встретили % начинаем парсить флаг, длину, точность, размер типа и сам спецификатор типа
		параллельно записываем в структуру все эти данные
	после парсинга % есть структура заполненная 
	отправляем её в функцию вывода
	выводим спецификатор
	возврат к шагу 1
	

	ТУДУ:
	расписать для каждого типа флаги
	рассмотреть совместимости флагов
	узнать про цвета
	fd
	запись в файл
	вывод двоичных чисел

	Пояснения.
	spec -	хранит:
			поданую строку
			аргументы для va_arg,
			количество байтов на выход(то что возвращает принтф)
			индекс текущего символа в поданой строке
	flag - хранит:
			все флаги

	bonus:
	добавить флаг q - смайлики :), :(, xD, Dx, 
	морзе  
*/