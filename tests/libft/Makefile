SRCS	= ${wildcard srcs/*.c}

OBJS	= ${SRCS:.c=.o}

LIB		= ft
LIBDIR	= ../../libft

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

BIN		= test.a

RM		= rm -f

all:	${BIN}

${BIN}:	${OBJS}
		${CC} ${CFLAGS} main.c ${OBJS} -L${LIBDIR} -l${LIB} -o ${BIN}

.c.o:
		${CC} ${CFLAGS} -c  $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${BIN}

re:		fclean all

.PHONY: all clean fclean re
