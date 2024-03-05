/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:18 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/05 13:07:19 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_all *manfredi)
{
	int	row;
	int	column;

	row = 1;
	column = 0;
	
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

// void	enemy_position(t_all *manfredi)
// {
// 	int	row;
// 	int	column;

// 	row = 1;
// 	while (manfredi->map.smap[row])
// 	{
// 		column = 0;
// 		while (manfredi->map.smap[row][column])
// 		{
// 			if (manfredi->map.smap[row][column] == 'E')
// 			{
// 				manfredi->enemy.i = row;
// 				manfredi->enemy.j = column;
// 				break ;
// 			}
// 			column++;
// 		}
// 		row++;
// 	}
// }

