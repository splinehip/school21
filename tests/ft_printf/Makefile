NAME		= test.a

SRCS		= ${wildcard *.c}

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		=

OPTFLAGS	= -O2

RM			= rm -f


all:		libft ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -L../../ft_printf -lftprintf -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft:
			@make -C ../../ft_printf re

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			libft fclean all

.PHONY: all so clean fclean re libft
