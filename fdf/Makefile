NAME		= fdf

LIBFT		= ./libft

MINILIBX	= ./minilibx

SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

INC_DIRS	= -L${LIBFT} -L${MINILIBX}

CFLAGS		= -g -Wall -Wextra -Werror

OPTFLAGS	=

RM			= rm -f


all:		libs ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${INC_DIRS} -lft -lmlx -lXext -lX11 -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libs:
			@make -C ${LIBFT}
			@make -C ${MINILIBX}

clean:
			${RM} ${OBJS} ${D_FILES}
			@make -C ${LIBFT} clean
			@make -C ${MINILIBX} clean

fclean:		clean
			${RM} ${NAME}
			@make -C ${LIBFT} fclean

re:			fclean all

.PHONY: all clean fclean re libs
