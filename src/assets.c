/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:28 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 17:47:34 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_img(t_all *manfredi)
{
	manfredi->img.front
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/player/front.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.back
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/player/back.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.left
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/player/left.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.right
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/player/right.xpm",
			&manfredi->img.size, &manfredi->img.size);
	manfredi->img.wall
		= (t_img *)mlx_xpm_file_to_image(manfredi->map.mlx,
			"./assets/wall.xpm",
			&manfredi->img.size, &manfredi->img.size);
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
