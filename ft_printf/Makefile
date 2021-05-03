NAME		= libftprintf.a

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}


D_FILES		= ${SRCS:.c=.d}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			@cd ./libft && make
			@cp ./libft/libft.a ./${NAME}
			ar -rs ${NAME} $?

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft_re:
			@cd ./libft && make re

clean:
			@cd ./libft && make clean
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			@cd ./libft && make fclean
			${RM} ${NAME}

re:			libft_re fclean all

.PHONY: all so clean fclean re libft_re
