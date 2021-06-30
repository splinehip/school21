NAME		= push_swap

LIBFT		= ./libft

SRCS		= main.c	argv_handler.c	find_largest.c	ft_rotate.c	push.c\
			  swap.c	sort_stack.c	print_stack.c	is_sorted.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	=

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
