/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:38:36 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/22 15:36:24 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  

void	open_window(t_all *manfredi)
{
	int	i;

	i = 0;
	while (manfredi->map.tmap[i])
		i++;
	manfredi->map.mlx = mlx_init();
	manfredi->map.win = mlx_new_window(manfredi->map.mlx,
	64 * ft_strlen(manfredi->map.tmap[0]), (64 * i + 64), "so_long");
}
