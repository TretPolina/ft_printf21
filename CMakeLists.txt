cmake_minimum_required(VERSION 3.16)
project(yPrintf4 C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(yPrintf4
        includes/ft_printf.h

        flags.c
        ft_atoi.c
        ft_itoa_base.c
        ft_printf.c
        ft_putchar.c
        ft_putstr.c
        ft_strdup.c
        ft_strlen.c
        main.c
        spec_c_s.c
        spec_d.c
        spec_o.c
        spec_percent.c
        spec_q.c
        spec_u.c
        spec_x_X.c
        specificator.c
        star.c)
