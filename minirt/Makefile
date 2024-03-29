include makefile.srcs

NAME			= miniRT

LOGFILE			= *.log

SRCS_DIR		= srcs

OBJS_DIR		= objs

OBJS			= ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

LIBFT			= libs/libft/libft.a

INC_HEADERS		= -Iheaders -I$(dir ${LIBFT})

INC_LIBS_DIR	= -L$(dir ${LIBFT})

INC_LIBS		=  -lft -lmlx -lm

OS_NAME			:= $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
	LIBMLX_DIR		= libs/libmlx/macos
	INC_LIBS		+= -framework OpenGL -framework AppKit
endif
ifeq ($(OS_NAME), Linux)
	LIBMLX_DIR		= libs/libmlx/linux
	INC_LIBS		+= -lXext -lX11 -lz
endif

LIBMLX			= ${LIBMLX_DIR}/libmlx.a

INC_HEADERS		+= -I${LIBMLX_DIR}

INC_LIBS_DIR	+= -L${LIBMLX_DIR}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -MMD -MP -g

RM			= rm -rf

all:		$(dir ${LIBFT}) ${LIBMLX_DIR} ${NAME}

${NAME}:	${OBJS} ${LIBFT} ${LIBMLX}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INC_LIBS_DIR} ${INC_LIBS}

.SECONDEXPANSION:
${OBJS}:	$$(patsubst %.o, %.c, $$(subst ${OBJS_DIR}/, ${SRCS_DIR}/, $${@}))
			@mkdir -p ${@D}
			${CC} ${DEBUG} ${CFLAGS} ${OPTFLAGS} ${INC_HEADERS} -c $< -o $@

$(dir ${LIBFT}):
			@make -C $@ $(MAKECMDGOALS)

${LIBMLX_DIR}:
			@make -C $@ $(MAKECMDGOALS)

clean:		$(dir ${LIBFT}) ${LIBMLX_DIR}
			${RM} ${OBJS_DIR}

fclean:		$(dir ${LIBFT})
			@make -C ${LIBMLX_DIR} clean
			${RM} ${OBJS_DIR}
			${RM} ${NAME} ${NAME}.dSYM ${LOGFILE}

re:			fclean all

.PHONY: all $(dir ${LIBFT}) ${LIBMLX_DIR} clean fclean re

-include ${OBJS:.o=.d}
