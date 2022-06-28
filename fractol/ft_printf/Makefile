# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 14:16:32 by marimatt          #+#    #+#              #
#    Updated: 2022/04/22 11:08:36 by marimatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

SRC 	=	*.c\

OBJ 	=	${SRC:.c=.o}

CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

bonus:
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f	$(OBJ)

fclean: clean
	/bin/rm -f	$(NAME)

re: fclean ${NAME}
