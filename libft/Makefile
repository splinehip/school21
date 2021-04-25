NAME		= libft.a

SRCS		=	ft_memset.c		ft_memcmp.c		ft_strnstr.c	ft_isascii.c\
				ft_bzero.c		ft_strlen.c		ft_strncmp.c	ft_isprint.c\
				ft_memcpy.c		ft_strlcpy.c	ft_atoi.c		ft_toupper.c\
				ft_memccpy.c	ft_strlcat.c	ft_isalpha.c	ft_tolower.c\
				ft_memmove.c	ft_strchr.c		ft_isdigit.c	ft_calloc.c\
				ft_memchr.c		ft_strrchr.c	ft_isalnum.c	ft_strdup.c\
				ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c\
				ft_itoa.c		ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_lstadd_front.c\
				ft_lstnew.c		ft_lstsize.c	ft_lstadd_back.c\
				ft_lstlast.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
				ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= clang

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
