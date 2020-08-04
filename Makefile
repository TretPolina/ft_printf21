# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fford <fford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:08:43 by fford             #+#    #+#              #
#    Updated: 2020/03/06 21:12:47 by fford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

.PHONY: all clean fclean re

SRC =	ft_printf.c specificator.c flags.c spec_x_check.c sub_func.c fourth_flag.c\
		spec_c_s.c spec_d_i.c spec_u.c spec_o.c spec_percent.c spec_x.c spec_p.c spec_f.c\
		ft_putchar.c ft_strlen.c ft_strdup.c ft_putstr.c\
		star.c spec_b.c\

OBJ = $(SRC:.c=.o)

OPTION = -c -I includes/ft_printf.h
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $<

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OPTION) $(SRC) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	
re: fclean all