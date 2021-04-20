NAME		= libft.a

SRCS		=	ft_memset.c		ft_memcpm.c		ft_strnstr.c\
				ft_bzero.c		ft_strlen.c		ft_strncmp.c\
				ft_memcpy.c		ft_strlcpy.c\
				ft_memccpy.c	ft_strlcat.c\
				ft_memmove.c	ft_strchr.c\
				ft_memchr.c		ft_strrchr.c

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
