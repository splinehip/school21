NAME	= test.out

SRCS	= main.c\
		  ../../ft_gnl/get_next_line.c\
		  ../../ft_gnl/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		= -g -Wall -Wextra -Werror -D BUFFER_SIZE=100 -I../../ft_gnl

OPTFLAGS	= -O0

RM			= rm -f


all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OPTFLAGS} ${OBJS} -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
