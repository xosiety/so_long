/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:59 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/19 18:04:13 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"  

void init (t_all *manfredi)
{
	manfredi->moves.ct_collect = 0;
	manfredi->img.size=64;
}

int main (int argc, char **argv)
{
	t_all manfredi;

if (argc != 2)
	{ 	
		printf ("ho fatto er botto fratelli \n");
		exit(1);
	}

init (&manfredi);
	
	int fd;
		char *gnl;

		fd=open(argv[1], 0_RDONLY);
		if (fd==-1)
			return(1);

		manfredi.map.smap=malloc(1);
		manfredi.map.smap[0]='\0';

		while(1)
		{
			gnl=get_next_line(fd);
			if(!gnl)
				break;
			manfredi.map.smap=ft_strjoin(manfredi.map.smap, gnl);
		free(gnl);
		manfredi.map.tmap=ft_split(manfredi.map.smap, '\n')
			close(fd);
		}

	
	int i;
		i=0
		while (manfredi.map.tmap[i])
			i++;


	manfredi.map.mlx=mlx_init();
	manfredi.map.win=mlx_new_window(manfredi.map.mlx, 64* ft_strlen //de la stringa 0 del file mappa);
	manfredi.map.win=mlx_new_window(manfredi.map.mlx (64*i)+64, "so_long");

    mlx_hook(win, 17, 0, close_window, mlx);
    mlx_hook(win, 2, 1L<<0, key_pressed, mlx);

    mlx_loop(mlx);

    return 0;
}	

