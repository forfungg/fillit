/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:17:32 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/07 11:41:24 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>

/*
**	Helpful definitions
*/

# define MS map->size
# define MT map->tile
# define ML map->lines
# define MV map->tile[i].value
# define MX map->tile[i].loc.x
# define MY map->tile[i].loc.y
# define MTX map->tile[TIP].loc.x
# define MTY map->tile[TIP].loc.y
# define TN tetrimino->name
# define TT tetrimino->tile
# define TP tetrimino->placed
# define TX tetrimino->tile[j].x
# define TY tetrimino->tile[j].y
# define TIX tetrimino[ti]->tile[j].x
# define TIY tetrimino[ti]->tile[j].y
# define TIN tetrimino[ti]->name
# define TIP tetrimino[ti]->placed
# define IBS is_bit_set

/*
** Coordinates struct for easier readibility of the code
*/

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

/*
**	Tile struct
*/

typedef struct	s_tile
{
	char		value;
	t_coords	loc;
}				t_tile;

/*
** Tetrimino struct
*/

typedef struct	s_tetrimino
{
	char		name;
	t_coords	tile[4];
	int			placed;
}				t_tetr;

/*
** Board/Map struct
*/

typedef struct	s_map
{
	int			size;
	t_tile		*tile;
}				t_map;

typedef struct	s_bmap
{
	int			size;
	int			*lines;
}				t_bmap;

/*
**	Input functions
*/

void			get_input(char *argv, t_tetr **tetros, int *t_cnt);
void			store_input(char *buf, int tetr_cnt, t_tetr **tetros);
void			ft_puterr(int x);

/*
**	Map functions
*/

int				init_map(t_map *map, int size);
int				tetr_to_map(t_map *map, t_tetr **tetrimino);
void			print_map(t_map *map);
int				place_tetriminos(t_map *map, t_tetr **tetrimino, int count);

/*
**	BitMaps
*/

int				init_bmap(t_bmap *map, int size);
void			print_bmap(t_bmap *map);
int				check_space(t_bmap *map, int org, t_tetr *tetrimino);
int				tetr_to_bmap(t_bmap *map, t_tetr *tetrimino, int position);
int				copy_bmap(t_bmap *dst, t_bmap *src);
int				init_cpy_bmap(t_bmap *map, t_bmap *org, int size);
int				place_tetr_bmap(t_bmap *map, t_tetr **tetrimino);
void			del_bmap(t_bmap *map);
int				check_neighb(t_bmap *map);
int				is_skip(t_bmap *map, t_tetr **tetrimino);
int				check_index(t_bmap *map, t_tetr **tetrimino, int ti);

/*
** Tetrimino functions
*/

void			copy_tetrimino(t_tetr *t1, t_tetr *t2);
int				check_tetrimino(t_tetr *tetrimino, t_map *map, int i);
void			print_tetrimino(t_tetr *tetrimino);
void			reset_tetriminos(t_tetr **tetrimino);
int				not_placed_tetr(t_tetr **tetrimino);

/*
** BIT operations functions
*/

int				is_bit_set(int x, int i);
int				set_bit(int x, int i);
int				clear_bit(int x, int i);
int				check_line(t_bmap *map, int i);

#endif
