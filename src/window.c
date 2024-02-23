/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:38:36 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/23 17:49:12 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  

void	open_window(t_all *manfredi)
{
	manfredi->map.mlx = mlx_init();
	manfredi->map.win = mlx_new_window(manfredi->map.mlx,
			manfredi->map.width * 64, manfredi->map.height * 64, "so_long");
}

void	new_window(t_all *manfredi)
{
	manfredi->img.size = 64;
}
