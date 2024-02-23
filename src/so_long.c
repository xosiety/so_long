/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:59 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 17:48:29 by afabbri          ###   ########.fr       */
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

void	close_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, 640, 640, "so_long");
	mlx_destroy_window(mlx, win);
	exit(0);
}

int	key_pressed(int keycode, t_all *manfredi)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.front, 0, 0);
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.back, 0, 0);
	}
	if (keycode == 0)
	{
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.left, 0, 0);
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win,
			manfredi->img.right, 0, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	manfredi;
	void	*win;
	void	*mlx;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("ho fatto er botto fratelli \n");
		exit(1);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 640, "so_long");
	init(&manfredi);
	ft_map(&manfredi, argv);
	open_window(&manfredi);
	mlx_key_hook(win, key_pressed, &manfredi);
	mlx_hook(win, 2, 1L << 0, key_pressed, mlx);
	mlx_loop(mlx);
	return (0);
}
