/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:37 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 21:09:21 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/time.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"

typedef struct s_map
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	char	*smap;
	char	**tmap;
}	t_map;

typedef struct s_img
{
	void	*front;
	void	*back;
	void	*right;
	void	*left;
	void	*wall;
	void	*collectible;
	void	*enemy;
	void	*exit;
	void	*floor;
	int		size;
}	t_img;

typedef struct s_moves
{
	int	ct_moves;
	int	ct_collect;
	int	i;
	int	j;

}	t_moves;

typedef struct s_all
{
	t_map	map;
	t_img	img;
	t_moves	moves;
}	t_all;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

void	init(t_all *manfredi);
void	new_window(t_all *manfredi);
void	take_img(t_all *manfredi);
void	put_img(t_all *manfredi);
void	move_up(t_all *manfredi);
void	move_down(t_all *manfredi);
void	move_left(t_all *manfredi);
void	move_right(t_all *manfredi);
void	check_path(t_all *manfredi);
void	check_map(t_all *manfredi);
void	check_arg(int argc, char **argv);
void	floor_check(t_all *manfredi);
void	wall_check(t_all *manfredi);
void	new_window(t_all *manfredi);
void	player_position(t_all *manfredi);
void	ft_map(t_all *manfredi, char **argv);
void	player_position(t_all *manfredi);
void	close_window(void *mlx);
void	put_player(t_all *manfredi);
void	put_collectible(t_all *manfredi);
void	put_exit(t_all *manfredi);
void	put_img(t_all *manfredi);
void	free_memory(t_all *manfredi);
int		key_input(int k, t_all *manfredi);

#endif
