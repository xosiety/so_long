/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:52:32 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 19:02:16 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void)
{
	exit(0);
}

void	xpm_to_img(t_all *manfredi)
{
	manfredi->img.front = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/front.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.back = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/back.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.right = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/right.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.left = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/left.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.wall = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/wall.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.collectible = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/item.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.enemy = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/enemy.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.exit = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/exit.xpm", &manfredi->img.size, &manfredi->img.size);
	manfredi->img.floor = mlx_xpm_file_to_image(manfredi->map.mlx, "assets/xpm/floor.xpm", &manfredi->img.size, &manfredi->img.size);
}

void put_img_to_window(t_all *manfredi)
{
	quit();
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.front, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.back, 0, 64);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.right, 64, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.left, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.wall, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.collectible, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.enemy, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.exit, 0, 0);
	mlx_put_image_to_window(manfredi->map.mlx, manfredi->map.win, manfredi->img.floor, 0, 0);
	mlx_hook(manfredi->map.win, 17, 0, quit, manfredi);
}

void	map_range(t_all *manfredi)
{
	int	i;

	i = 0;
	while (manfredi->map.tmap[i])
		i++;
	manfredi->map.height = i;
	manfredi->map.width = ft_strlen((const char *)manfredi->map.tmap[0]);
}

void	ft_map(t_all *manfredi, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file non trovato fratelli\n");
		exit(1);
	}
	init(manfredi);
	{
		manfredi->map.tmap[i] = ft_strdup(line);
		free(line);
		i++;
	}
	manfredi->map.tmap[i] = ft_strdup(line);
	free(line);
	close(fd);
}

// void	ft_map(t_all *manfredi, char **argv)
// {
// 	int		fd;
// 	char	*gnl;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return ;
// 	manfredi->map.smap = malloc(1);
// 	manfredi->map.smap[0] = '\0';
// 	while (1)
// 	{
// 		gnl = get_next_line(fd);
// 		if (!gnl)
// 			break ;
// 		manfredi->map.smap = ft_strjoin(manfredi->map.smap, gnl);
// 		free(gnl);
// 	}
// 	manfredi->map.tmap = ft_split(manfredi->map.smap, '\n');
// 	close(fd);
// 	map_range(manfredi);
// }


