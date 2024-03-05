/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:28 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/05 10:42:10 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_img2(t_all *manfredi)
{
	manfredi->img.collectible
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/item.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.enemy
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/enemy.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.exit
	= mlx_xpm_file_to_image(manfredi->map.mlx,
		"./assets/xpm/exit.xpm", &manfredi->img.size, &manfredi->img.size);
}

void	take_img(t_all *manfredi)
{
	manfredi->img.front
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/front.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.back
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/back.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.left
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/left.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.right
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/right.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.wall
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/wall.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.floor
		= mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/xpm/floor.xpm", &manfredi->img.size, &manfredi->img.size);
	 take_img2(manfredi);
}

void	draw_map(t_all *manfredi)
{
	int	i;
	int	j;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap)
		{
			if (manfredi->map.tmap[i][j] == '1')
				mlx_put_image_to_window(manfredi->map.mlx,
					manfredi->map.win, manfredi->img.wall,
					j * manfredi->img.size, i * manfredi->img.size);
			else if (manfredi->map.tmap[i][j] == '0')
				mlx_put_image_to_window(manfredi->map.mlx,
					manfredi->map.win, manfredi->img.floor,
					j * manfredi->img.size, i * manfredi->img.size);
			else if (manfredi->map.tmap[i][j] == 'C')
				mlx_put_image_to_window(manfredi->map.mlx,
					manfredi->map.win, manfredi->img.collectible,
					j * manfredi->img.size, i * manfredi->img.size);
			else if (manfredi->map.tmap[i][j] == 'E')
				mlx_put_image_to_window(manfredi->map.mlx,
					manfredi->map.win, manfredi->img.exit,
					j * manfredi->img.size, i * manfredi->img.size);
			else if (manfredi->map.tmap[i][j] == 'P')
				mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.front,
					j * manfredi->img.size, i * manfredi->img.size);
			else if (manfredi->map.tmap[i][j] == 'X')
				mlx_put_image_to_window(manfredi->map.mlx,
					manfredi->map.win, manfredi->img.enemy,
					j * manfredi->img.size, i * manfredi->img.size);
			j++;
		}
		i++;
	}
}

void	put_img(t_all *manfredi)
{
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
		manfredi->img.front, manfredi->moves.j * manfredi->img.size,
		manfredi->moves.i * manfredi->img.size); 