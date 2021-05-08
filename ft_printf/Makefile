NAME		= libftprintf.a

SRCS		= ft_printf.c	ft_printf_isconvsymbol.c	ft_printf_getres.c\
			  ft_printf_getconversion.c	ft_printf_flag_handler.c\
			  ft_printf_wp_handler.c	ft_printf_c_handler.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

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
