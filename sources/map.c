/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:26:20 by afabbri           #+#    #+#             */
/*   Updated: 2024/03/03 19:59:43 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	*gnl;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ;
	manfredi->map.smap = malloc(1);
	manfredi->map.smap[0] = '\0';
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		manfredi->map.smap = ft_strjoin(manfredi->map.smap, gnl);
		free(gnl);
	}
	manfredi->map.tmap = ft_split(manfredi->map.smap, '\n');
	close(fd);
	map_range(manfredi);
}
