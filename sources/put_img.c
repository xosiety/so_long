/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:52:32 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 19:02:16 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img2(t_all *manfredi, int i, int j)
{
	if (manfredi->map.tmap[i][j] == 'C')
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.collectible, j * 64, (i) * 64);
	else if (manfredi->map.tmap[i][j] == 'P')
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.right, j * 64, (i) * 64);}
	else if (manfredi->map.tmap[i][j] == 'N')
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.enemy, j * 64, (i) * 64);
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
					manfredi->img.wall, j * 64, (i) * 64);
			else if (manfredi->map.tmap[i][j] == '0')
				mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
					manfredi->img.floor, j * 64, (i) * 64);
			else if (manfredi->map.tmap[i][j] == 'E')
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.exit, j * 64, (i) * 64);}
			else if (manfredi->map.tmap[i][j] == 'C' || manfredi->map.tmap[i][j] == 'P' || manfredi->map.tmap[i][j] == 'N');
				put_img2(manfredi, i, j);
			j++;
		}
		i++;
	}
}

void	print_map(t_all *manfredi)
{
	int	i;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		ft_printf("%s\n", manfredi->map.tmap[i]);
		i++;
	}
}