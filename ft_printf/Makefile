NAME		= libftprintf.a

SRCS		= ft_printf.c					ft_printf_get_conversions.c\
			  ft_printf_update_args_res.c	ft_printf_apply_handlers.c\
			  ft_printf_flag_handler.c		ft_printf_wp_handler.c\
			  ft_printf_c_handler.c			ft_printf_s_handler.c\
			  ft_printf_diu_handler.c		ft_printf_p_handler.c\
			  ft_printf_xX_handler.c		ft_printf_prc_handler.c

OBJS		:= ${SRCS:.c=.o}

D_FILES		:= ${SRCS:.c=.d}

LIBFTD		:= ./libft

LIBFT		:= ${LIBFTD}/libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

OPTFLAGS	= -O2

RM			= rm -f


all:		libft ${NAME}

${NAME}:	${OBJS}
			@cp -r ${LIBFT} ${NAME}
			ar -crs ${NAME} $?

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

bonus:		all

libft:
			@make -C ${LIBFTD} bonus

clean:
			${RM} ${OBJS} ${D_FILES}
			@make -C ${LIBFTD} clean

fclean:		clean
			${RM} ${NAME}
			@make -C ${LIBFTD} fclean

re:			fclean all

.PHONY: all bonus clean fclean re libft
