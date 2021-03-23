# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 09:36:12 by fcoudert          #+#    #+#              #
#    Updated: 2021/03/22 11:09:16 by fcoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo_one

SRCS	= main.c init.c eat_sleep_think.c monitor.c start_thread.c check.c ./basic/atoi.c ./basic/basic.c manage_time.c ./basic/ft_itoa.c ./basic/ft_strjoin.c

OBJS	= ${SRCS:.c=.o}

INCLUDE = ./

CFLAGS = -Wall -Wextra -Werror -g3 -I.

RM		= rm -f 


all:	$(NAME)


$(NAME) : ${OBJS}
	gcc ${CFLAGS} -o ${NAME} ${OBJS} -lpthread

clean:		
			/bin/rm -f ${OBJS}
			
fclean:		clean
			/bin/rm -f ${NAME}

re:			fclean all