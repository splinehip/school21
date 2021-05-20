NAME		= test.a

SRCS		= ${wildcard *.c}

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= clang

CFLAGS		= -Wformat

OPTFLAGS	= -O2

RM			= rm -f


all:		${NAME}

${NAME}:	${OBJS}
			@cd ../../ft_printf && make
			${CC} ${CFLAGS} ${OBJS} -L../../ft_printf -lftprintf -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft:
			@cd ../../ft_printf && make

libft_re:
			cd ../../ft_printf && make re

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			libft fclean all

reall:		libft_re fclean all

.PHONY: all so clean fclean re libft_re
