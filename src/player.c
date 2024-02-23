/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:18 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 16:44:38 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_all *manfredi)
{
	int	row;
	int	column;

	row = 1;
	enemy_position(manfredi);
	while (manfredi->map.smap[row])
	{
		if (manfredi->map.tmap[row][column] == 'P')
		{
			manfredi->moves.i = row;
			manfredi->moves.j = column;
			break ;
		}
		column++;
	}
	row++;
}

int	key_hook(int keycode, t_all *manfredi)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		move_up(manfredi);
	if (keycode == 1)
		move_down(manfredi);
	if (keycode == 0)
		move_left(manfredi);
	if (keycode == 2)
		move_right(manfredi);
	return (0);
}

void	init(t_all *manfredi)
{
	mlx_key_hook(manfredi->map.win, key_hook, manfredi);
	mlx_loop(manfredi->map.mlx);
}
