NAME		= libft.a

SRCS		=	ft_memset.c		ft_memcmp.c		ft_strnstr.c	ft_isascii.c\
				ft_bzero.c		ft_strlen.c		ft_strncmp.c	ft_isprint.c\
				ft_memcpy.c		ft_strlcpy.c	ft_atoi.c		ft_toupper.c\
				ft_memccpy.c	ft_strlcat.c	ft_isalpha.c	ft_tolower.c\
				ft_memmove.c	ft_strchr.c		ft_isdigit.c	ft_calloc.c\
				ft_memchr.c		ft_strrchr.c	ft_isalnum.c	ft_strdup.c\
				ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c\
				ft_itoa.c		ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_strjoinchr.c	ft_uintpow.c\
				ft_tobase.c		ft_strtolower.c	ft_uitoa.c		ft_strljoinchr.c

SRCS_B		=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c\
				ft_lstadd_back.c	ft_lstlast.c		ft_lstdelone.c\
				ft_lstclear.c		ft_lstiter.c 		ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${SRCS_B:.c=.o}

D_FILES		= ${SRCS:.c=.d} ${SRCS_B:.c=.d}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar -crs ${NAME} $?

bonus:
			@make OBJS='${OBJS_B}' all

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

so:			${OBJS} ${OBJS_B}
			${CC} ${OBJS} ${OBJS_B} -shared -o libft.so

include ${wildcard ${D_FILES}}

clean:
			${RM} ${OBJS} ${OBJS_B} ${D_FILES} libft.so

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all bonus so clean fclean re
