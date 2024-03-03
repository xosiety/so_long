/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:28 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 21:10:12 by afabbri          ###   ########.fr       */
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
