NAME		= test.a

SRCS		= main.c	${wildcard srcs/*.c}

OBJS		= ${SRCS:.c=.o}

LIB			= ft
LIBDIR		= ../../libft

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iincludes

OPTFLAGS	= -O2

RM			= rm -f

all:	libft ${NAME}

libft:
		@make -C ../../libft

${NAME}:${OBJS}
		${CC} ${CFLAGS} ${OBJS} -L${LIBDIR} -l${LIB} -lbsd -o ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c  $< -o $@

clean:
		${RM} ${OBJS}
		@make -C ../../libft clean

fclean:	clean
		${RM} ${NAME}
		@make -C ../../libft fclean

re:		fclean all

.PHONY: all clean fclean re
