# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 18:55:07 by afabbri           #+#    #+#              #
#    Updated: 2024/03/03 20:18:44 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_MAIN		=	./mlx
MLX				=	$(MINILIBX_MAIN)/libmlx.a
LIBFT_MAIN		=	./libft
LIBFT			=	$(LIBFT_MAIN)/libft.a
PRINTF_MAIN		=   ./printf
PRINTF			=   $(PRINTF_MAIN)/libftprintf.a
GNL_MAIN		=   ./gnl
MINILIBX		=	./libmlx.dylib
MINIFLAG		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME = so_long

FLAG = -Wall -Wextra -Werror

SRCS = sources/so_long.c sources/window.c sources/map.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		sources/put_img.c sources/assets.c sources/moves.c sources/player.c sources/check.c 

OBJ = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF)
				gcc ${FLAG} -c $(SRCS) -Imlx
				gcc $(OBJ) $(LIBFT) $(PRINTF) $(MINIFLAG) -o $(NAME)
				@echo "object created"

$(MLX):
				make -C $(MINILIBX_MAIN)

$(LIBFT):
				make -C $(LIBFT_MAIN)

$(PRINTF):
				make -C $(PRINTF_MAIN)

clean:
	@rm -f ${OBJ}
	make clean -C ${LIBFT_MAIN}
	make clean -C ${PRINTF_MAIN}
	rm -rf *o
	@echo "objects deleted"

fclean: clean
	@rm -rf ${NAME}
	rm -f $(MINILIBX)
	rm -f $(LIBFT)
	rm -f $(PRINTF)
	@echo "${NAME} deleted"

re: fclean all

all: ${NAME}

re: fclean all

