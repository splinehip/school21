SRCS	= srcs/ft_memset.c

OBJS	= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

BIN		= libft.a

RM		= rm -rf

all:	${BIN}

${BIN}:	${OBJS}
		${CC} ${CFLAGS} main.c ${OBJS} -o ${BIN}

.c.o:
		${CC} ${CFLAGS} -c  $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${BIN}

.PHONY: all clean fclean
