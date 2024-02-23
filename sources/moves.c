/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:15 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 19:09:34 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int k, t_all *manfredi)
{
	if (k == 13 || k == 126)
	{
		manfredi->img.back = manfredi->img.back;
		move_up(manfredi);
	}
	else if (k == 1 || k == 125)
	{
		manfredi->img.front = manfredi->img.front;
		move_down(manfredi);
	}
	else if (k == 2 || k == 124)
	{
		manfredi->img.right = manfredi->img.right;
		move_right(manfredi);
	}
	else if (k == 0 || k == 123)
	{
		manfredi->img.left = manfredi->img.left;
		move_left(manfredi);
	}
	else if (k == 53)
	{
		free_memory(manfredi);
	}
	return (0);
}

void	move_up(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i - 1][manfredi->moves.j] != '1')
	{
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j] = '0';
		manfredi->map.tmap[manfredi->moves.i - 1]
		[manfredi->moves.j] = 'P';
		manfredi->moves.i--;
	}
}

void	move_down(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i + 1][manfredi->moves.j] != '1')
	{
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j] = '0';
		manfredi->map.tmap[manfredi->moves.i + 1]
		[manfredi->moves.j] = 'P';
		manfredi->moves.i++;
	}
}

void	move_left(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i][manfredi->moves.j - 1] != '1')
	{
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j] = '0';
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j - 1] = 'P';
		manfredi->moves.j--;
	}
}

void	move_right(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j + 1] != '1')
	{
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j] = '0';
		manfredi->map.tmap[manfredi->moves.i]
		[manfredi->moves.j + 1] = 'P';
		manfredi->moves.j++;
	}
}
