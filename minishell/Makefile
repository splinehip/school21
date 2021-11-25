NAME		= minishell

LIBFT		= ./libs/libft

SRCS_DIR	= srcs

OBJS_DIR	= objs

SRCS		= minishell.c	argv_handler/main.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

INCLUDES	= -I./headers

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O3

RM			= rm -rf

vpath %.c ${SRCS_DIR}

all:		libft ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $(addprefix ${OBJS_DIR}/, ${OBJS}) \
			-L${LIBFT} -lft -o ${NAME}

%.o:		%.c
			@mkdir -p ${OBJS_DIR}/${@D}
			${CC} ${CFLAGS} ${OPTFLAGS} ${INCLUDES} -c $< -o ${OBJS_DIR}/$@ -MD

include $(wildcard ${D_FILES})

libft:
			@make -C ${LIBFT}

rmobjs:
			${RM} ${OBJS_DIR}

clean:		rmobjs
			@make -C ${LIBFT} clean

fclean:		rmobjs
			${RM} ${NAME}
			@make -C ${LIBFT} fclean

re:			fclean all

.PHONY: all libft rmobjs clean fclean re
