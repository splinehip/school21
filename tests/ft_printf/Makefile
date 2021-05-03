NAME		= test.a

SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			@cd ../../ft_printf && make
			${CC} ${CFLAGS} ${OBJS} -L../../ft_printf -lftprintf -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft_re:
			cd ../../ft_printf && make re

clean:
			${RM} ${OBJS} ${D_FILES}
			cd ../../ft_printf && make clean

fclean:		clean
			${RM} ${NAME}
			cd ../../ft_printf && make fclean

re:			libft_re fclean all

.PHONY: all so clean fclean re libft_re
