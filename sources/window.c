/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:38:36 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 18:58:38 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static int	quit(void)
{
	exit(0);
}

void	new_window(t_all *manfredi)
{
	manfredi->map.mlx = mlx_init();
	manfredi->map.win = mlx_new_window
		(manfredi->map.mlx, manfredi->map.width * 64,
			manfredi->map.height * 64, "so_long");
	mlx_hook(manfredi->map.win, 17, 0, quit, 0);
}

void	close_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, 640, 640, "so_long");
	mlx_destroy_window(mlx, win);
	exit(0);
}

void	put_img(t_all *manfredi)
{
	int	i;
	int	j;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap
			[i][j])
		{
			if (manfredi->map.tmap[i][j] == '1')
				mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
					manfredi->img.wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
