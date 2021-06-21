NAME		= pipex

LIBFT		= ./libft

SRCS		= main.c	path_handler.c	argv_handler.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f


all:		libft ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -L${LIBFT} -lft -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libft:
			@make -C ${LIBFT}

clean:
			${RM} ${OBJS} ${D_FILES}
			@make -C ${LIBFT} clean

fclean:		clean
			${RM} ${NAME}
			@make -C ${LIBFT} fclean

re:			fclean all

.PHONY: all clean fclean re libft
