# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 18:55:07 by afabbri           #+#    #+#              #
#    Updated: 2024/02/19 19:35:04 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_MAIN		=	./mlx
MLX				=	$(MINILIBX_MAIN)/libmlx.a
LIBFT_MAIN		=	./libft
LIBFT			=	$(LIBFT_MAIN)/libft.a
PRINTF_MAIN		=   ./ft_printf
PRINTF			=   $(PRINTF_MAIN)/libftprintf.a
GNL_MAIN		=   ./get_next_line
GNL				=   $(GNL_MAIN)/get_next_line.a
MINILIBX		=	./libmlx.dylib
MINIFLAG		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME = so_long

FLAG = -Wall -Wextra -Werror

SRCS = src/so_long.c src/window.c src/map.c

OBJ = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF) $(GNL)
				gcc ${FLAG} -c $(SRCS) -Imlx
				gcc $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MINIFLAG) -o $(NAME)
				@echo "object created"

$(MLX):
				make -C $(MINILIBX_MAIN)
				
clean:
	@rm -f ${OBJ}
	@echo "objects deleted"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted"

all: ${NAME}

re: fclean all

