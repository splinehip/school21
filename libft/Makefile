NAME		= libft.a

SRCS		=	ft_memset.c		ft_memcpm.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_memchr.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar -crs ${NAME} $?

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
