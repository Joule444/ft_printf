# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 14:56:58 by tmejri            #+#    #+#              #
#    Updated: 2022/05/23 12:18:29 by jthuysba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_printf.c functions1.c functions2.c \

OBJS			= ${SRCS:.c=.o}

NAME			= libftprintf.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re
