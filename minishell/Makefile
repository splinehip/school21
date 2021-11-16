NAME		= minishell

LIBFT		= ./libft

SRCS		= minishell.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O3

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

fclean:
			${RM} ${OBJS} ${D_FILES} ${NAME}
			@make -C ${LIBFT} fclean

re:			fclean all

.PHONY: all libft clean fclean re
