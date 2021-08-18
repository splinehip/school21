NAME		= fdf

LIBFT		= ./libft

MINILIBX	= ./minilibx

SRCS		= main.c\
			  hooks/hooks_reg.c 	hooks/close_win.c	hooks/key_press.c\
			  hooks/mouse_btn.c		hooks/mouse_move.c	hooks/ptr_enter_win.c\
			  hooks/ptr_leave_win.c	hooks/key_reales.c	trgb.c\
			  draw_point.c			draw_line.c			argv_handler.c\
			  #display_map.c

OBJS		= ${SRCS:.c=.o}

D_FILES		= ${SRCS:.c=.d}

CC			= cc

INC_DIRS	= -L${LIBFT} -L${MINILIBX}

INC_LIBS	= -lft -lmlx -lXext -lX11 -lm -lz

CFLAGS		= -g -Wall -Wextra -Werror

#OPTFLAGS	= -O3

RM			= rm -f


all:		libs ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${INC_DIRS} ${INC_LIBS} -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

libs:
			@make -C ${LIBFT}
			@make -C ${MINILIBX}

clean:
			${RM} ${OBJS} ${D_FILES}
			@make -C ${LIBFT} clean
			@make -C ${MINILIBX} clean

fclean:		clean
			${RM} ${NAME}
			@make -C ${LIBFT} fclean

re:			fclean all

.PHONY: all clean fclean re libs
