/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:59 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/05 10:09:16 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  
#include "../libft/libft.h" 
#include "../mlx/mlx.h"

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

void	init(t_all *manfredi)
{
	manfredi->moves.ct_collect = 0;
	manfredi->img.size = 64;
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
	// print_map(&manfredi);
	// floor_check(&manfredi);
	new_window(&manfredi);
	take_img(&manfredi);
	put_img(&manfredi);
	mlx_key_hook(manfredi.map.win, key_input, &manfredi);
	//loop per il nemico
	mlx_loop(manfredi.map.mlx);
	write(1, "ciao6\n", 6);
	free_memory(&manfredi);
	return (0);
}
