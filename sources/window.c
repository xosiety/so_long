/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:38:36 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 20:03:36 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static int	quit(void)
{
	exit(0);
}

void	new_window(t_all *manfredi)
{
	manfredi->map.mlx = mlx_init();
	manfredi->map.win = mlx_new_window
		(manfredi->map.mlx, manfredi->map.width * 64,
			(manfredi->map.height * 64 + 64), "so_long");
	mlx_hook(manfredi->map.win, 17, 0, quit, 0);
}
