/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:15 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 16:44:11 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
