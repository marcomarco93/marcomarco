# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:38:23 by marimatt          #+#    #+#              #
#    Updated: 2022/05/02 12:25:34 by marimatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fractol

SRC 	=	check_inputs.c draw_fractal.c fractal_functions.c\
			hooks.c main.c utils.c newton_fractal.c\

BONUS	=	newton_fractal.c check_inputs.c draw_fractal.c fractal_functions.c\
			hooks.c main_bonus.c utils.c\

CFLAGS	=	-Wall -Werror -Wextra

MY_LIBS	=	./libft/libft.a ./ft_printf/libftprintf.a\

INCLUDES =	-lm -lmlx

FRAMEWORKS	=	-framework OpenGL -framework AppKit

SRC_OBJ	=	$(SRC:.c=.o)

BONUS_OBJ	=	$(BONUS:.c=.o)

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@ 

all:	$(NAME)

$(NAME): $(SRC_OBJ)
	make re -C libft
	make re -C ft_printf
	make -C minilibx_mms
	gcc $(CFLAGS) $(SRC_OBJ) $(MY_LIBS) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)

bonus:	$(BONUS_OBJ)
	make re -C libft
	make re -C ft_printf
	make -C minilibx_mms
	gcc $(CFLAGS) $(BONUS_OBJ) $(MY_LIBS) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)

clean:
	/bin/rm -f	*.o
	make -C libft clean
	make -C ft_printf clean
	make -C minilibx_mms clean

fclean: clean
	/bin/rm -f	$(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean ${NAME}

.PHONY: re fclean clean	bonus fractol all