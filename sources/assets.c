/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:28 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 19:53:30 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_img(t_all *manfredi)
{
	manfredi->img.front
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/player/front.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.back
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/player/back.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.left
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/player/left.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.right
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/player/right.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.wall
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/wall.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.exit
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/exit.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.floor
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/floor.xpm", &manfredi->img.size, &manfredi->img.size);
}

void	put_img(t_all *manfredi)
{
	int	i;
	int	j;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap[i][j])
		{
			if (manfredi->map.tmap[i][j] == '1')
				mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
					manfredi->img.wall, j * 64, i * 64);
		}
	}
}

void	put_player(t_all *manfredi)
{
	mlx_put_image_to_window
		(manfredi->map.mlx, manfredi->map.win, manfredi->img.front, 0, 0);
}

void	put_collectible(t_all *manfredi)
{
	int	i;
	int	j;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap[i][j])
		{
			if (manfredi->map.tmap[i][j] == 'C')
				mlx_put_image_to_window
					(manfredi->map.mlx, manfredi->map.win,
						manfredi->img.collectible, j * 64, i * 64);
		}
	}
}

void	put_exit(t_all *manfredi)
{
	int	i;
	int	j;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap[i][j])
		{
			if (manfredi->map.tmap[i][j] == 'E')
				mlx_put_image_to_window
					(manfredi->map.mlx, manfredi->map.win,
						manfredi->img.exit, j * 64, i * 64);
		}
	}
}
