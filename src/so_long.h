/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:24:37 by afabbri           #+#    #+#             */
/*   Updated: 2024/02/19 18:04:09 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/time.h>
// # include "mlx/mlx.h"
//# include "libft/libft.h"
//# include "gnl/get_next_line.h"

typedef struct s_map {
	void *mlx;
	void *win;
	char *smap;
	char **tmap;
} t_map;

typedef struct s_img {
	void *img01;
	int size;
} t_img;

typedef struct s_moves{
	int ct_moves;
	int ct_collect;
 
} t_moves;

typedef struct s_all {
	t_map map;
	t_img img;
	t_moves moves;
} t_all;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
#endif
