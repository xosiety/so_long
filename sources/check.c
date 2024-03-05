/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:30:46 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/05 10:43:20 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i][manfredi->moves.j] == 'E'
		&& manfredi->moves.ct_collect == manfredi->map.ct_collect)
	{
		ft_printf("You win! \n");
		free_memory(manfredi);
	}
}

void	check_map(t_all *manfredi)
{
	if (manfredi->map.tmap[manfredi->moves.i][manfredi->moves.j] == 'C')
	{
		manfredi->map.tmap[manfredi->moves.i][manfredi->moves.j] = '0';
		manfredi->moves.ct_collect++;
	}
}	

void	check_path(t_all *manfredi)
{
	int	i;
	int	j;
	int	len;


	len = ft_strlen((const char *)manfredi->map.tmap[0]);
	i = 0;
	while (manfredi->map.tmap[i])
	{
		j = 0;
		while (manfredi->map.tmap[i][j])
			j++;
		if (j != len)
		{
			ft_printf("mappa non conforme fratelli'\n");
			exit (1);
		}
		i++;
	}
}

void	wall_check(t_all *manfredi)
	{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(manfredi->map.tmap[0]) - 1;
	while (manfredi->map.tmap[i])
	{
		if (manfredi->map.tmap[i][0] != '1' ||
		manfredi->map.tmap[i][len] != '1')
		{
			ft_printf("mappa non conforme fratelli'");
			exit (1);
		}
		i++;
	}
	check_path(manfredi);
}

void	floor_check(t_all *manfredi)
{
	int	i;

	i = 0;
	while (manfredi->map.tmap[i])
	{
		if (manfredi->map.tmap[0][i] != '1' ||
		(manfredi->map.tmap[ft_strlen((const char *)
		manfredi->map.tmap[i]) - 1][i]) != '1')
		{
			ft_printf("mappa non conforme\n");
			exit (1);
		}
		i++;
	}
	wall_check(manfredi);
}
