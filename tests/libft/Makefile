NAME		= test.a

SRCS		= main.c	${wildcard srcs/*.c}

OBJS		= ${SRCS:.c=.o}

LIB			= ft
LIBDIR		= ../../libft

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -Iincludes

OPTFLAGS	= -O2

RM			= rm -f

all:	libft ${NAME}

libft:
		cd ../../libft && make

${NAME}:${OBJS}
		${CC} ${CFLAGS} ${OBJS} -L${LIBDIR} -l${LIB} -lbsd -o ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c  $< -o $@

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

libft_re:
		cd ../../libft && make fclean

re:		libft_re fclean all

.PHONY: all clean fclean re
