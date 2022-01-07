include makefile.srcs

NAME			= minishell

SRCS_DIR		= srcs

OBJS_DIR		= objs

OBJS			= ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

LIBFT			= libs/libft/libft.a

LIBREADLINE		= libs/libreadline

INC_HEADERS		= -Iheaders -I$(dir ${LIBFT})

INC_LIBS_DIR	= -L$(dir ${LIBFT})

INC_LIBS		=  -lft

OS_NAME			:= $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
	INC_HEADERS		+= -I${LIBREADLINE}/include
	INC_LIBS_DIR	+= -L${LIBREADLINE}/lib -L/usr/local/opt/readline/lib
	INC_LIBS		+= -lncurses
	OS_V			:= $(shell sw_vers -productVersion | cut -f1,2 -d.)
ifeq ($(shell echo "$(OS_V) <= 10.14" | bc), 1)
	INC_LIBS		+= -lreadline_macos_v10_14
else
	INC_LIBS		+= -lreadline_macos_v10_15
endif
else
	INC_LIBS		+= -lreadline
endif

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -MMD -MP -g

RM			= rm -rf

all:		$(dir ${LIBFT}) ${NAME}

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INC_LIBS_DIR} ${INC_LIBS}

.SECONDEXPANSION:
${OBJS}:	$$(patsubst %.o, %.c, $$(subst ${OBJS_DIR}/, ${SRCS_DIR}/, $${@}))
			@mkdir -p ${@D}
			${CC} ${CFLAGS} ${OPTFLAGS} ${INC_HEADERS} -c $< -o $@

$(dir ${LIBFT}):
			@make -C $@ $(MAKECMDGOALS)

clean:		$(dir ${LIBFT})
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME} ${NAME}.dSYM

re:			fclean all

.PHONY: all $(dir ${LIBFT}) clean fclean re

-include ${OBJS:.o=.d}
