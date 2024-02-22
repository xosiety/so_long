/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:59 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/22 15:02:19 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  

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
		ft_printf ("ho fatto er botto fratelli \n");
		exit(1);
	}
	init(&manfredi);
	/* mlx_hook(win, 17, 0, close_window, mlx);
	mlx_hook(win, 2, 1L<<0, key_pressed, mlx);
	mlx_loop(mlx); */
	return (0);
}
