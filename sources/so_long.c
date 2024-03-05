/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:59 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/05 13:01:02 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  
#include "../libft/libft.h" 
#include "../mlx/mlx.h"

void	init(t_all *manfredi)
{
	manfredi->moves.ct_collect = 0;
	manfredi->img.size = 64;
}

void	free_memory(t_all *manfredi)
{
	int	i;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		free(manfredi->map.tmap[i]);
		i++;
	}
	free(*manfredi->map.tmap);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.right);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.left);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.back);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.front);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.wall);
	mlx_destroy_image(manfredi->map.mlx, manfredi->img.exit);
	free(manfredi->map.mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_all	manfredi;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("ho fatto er botto fratelli \n");
		exit(1);
	}
	init(&manfredi);
	ft_map(&manfredi, argv);
	map_range(&manfredi);
	check_path(&manfredi);
	check_map(&manfredi);
	wall_check(&manfredi);
	floor_check(&manfredi);
	mlx_new_window(manfredi.map.mlx, manfredi.map.width * 64, manfredi.map.height * 64, "so_long");
	xpm_to_img(&manfredi);
	put_img_to_window(&manfredi);
	mlx_key_hook(manfredi.map.win, key_input, &manfredi);
	//loop per il nemico
	mlx_loop(manfredi.map.mlx);
	free_memory(&manfredi);
	return (0);
}
