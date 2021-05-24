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
			${CC} ${CFLAGS} ${OBJS} -L../../libft -lft -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft:
			@make -C ../../libft

clean:
			${RM} ${OBJS} ${D_FILES}
			@make -C ../../libft clean

fclean:		clean
			${RM} ${NAME}
			@make -C ../../libft fclean

re:			libft fclean all

.PHONY: all clean fclean re libft
