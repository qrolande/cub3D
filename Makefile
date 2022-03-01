NAME 		=	cub3D

SRCS  		=	source/main.c \
				source/key_scan.c \
				source/end_game.c \
				source/game_begin.c \
				source/error_out.c \
				source/init_mem.c \
				source/parser.c

OBJS		=	${SRCS:.c=.o}

CC			= 	gcc -g

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

MLX			=	-lmlx -framework OpenGL -framework AppKit

INCLUDES	=	incl/cub3D.h

LIBFT		=	./libft/libft.a

%.o : %.c	$(INCLUDES)
			${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			${MAKE} -C ./libft
			${MAKE} bonus -C ./libft
			${CC} ${CFLAGS} ${MLX} ${OBJS} ${LIBFT} -o ${NAME}
			@echo "Make done"

clean:		
			@${MAKE} clean -C ./libft
			@${RM} ${OBJS}
			@echo "Make clean done" 

fclean:		
			@${MAKE} fclean -C ./libft
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "Make fclean done"

re:			fclean all

.PHONY:		all clean fclean re