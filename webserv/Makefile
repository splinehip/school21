include makefile.srcs

NAME		= webserv

SRCS_DIR	= srcs

OBJS_DIR	= objs

OBJS		= ${addprefix ${OBJS_DIR}/, ${SRCS:.cpp=.o}}

HEADERS	= -Iheaders

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -pthread -std=c++98

OPTFLAGS	= -MMD -MP -ggdb

RM			= rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.SECONDEXPANSION:
${OBJS}:	$$(patsubst %.o, %.cpp, $$(subst ${OBJS_DIR}/, ${SRCS_DIR}/, $${@}))
			@mkdir -p ${@D}
			${CC} ${CFLAGS} ${OPTFLAGS} ${HEADERS} -c $< -o $@

clean:
			${RM} ${OBJS_DIR}

fclean:
			${RM} ${NAME} ${NAME}.log ${OBJS_DIR}

re:			fclean all

.PHONY: all clean fclean re

-include ${OBJS:.o=.d}
