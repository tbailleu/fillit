/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:43:21 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 17:21:01 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*map_new(int size)
{
	t_map	*map;

	map = NULL;
	throw_error(!(map = (t_map *)malloc(sizeof(*map))), "error");
	map->size = size;
	map->bits = (t_uint192){0, 0, 0};
	return (map);
}

int		map_solved(t_map *map, t_tetri *tetri)
{
	int pos;

	if (tetri->t == 0)
		return (1);
	pos = 0;
	while (pos <= map->size * map->size)
	{
		if (place_tetri(map, pos, tetri) == 1)
		{
			if (map_solved(map, &tetri[1]) == 1)
				return (1);
			remove_tetri(map, pos, tetri);
		}
		pos++;
	}
	return (0);
}

t_map	map_solver(t_tetri *tetri)
{
	t_map	*map;
	int		size;
	int		i;

	size = 0;
	map = NULL;
	while (tetri[size].t)
		tetri[size++].tr = (t_uint192){0, 0, 0};
	size = ft_sqrt(size * 4);
	map = map_new(size);
	while (!map_solved(map, tetri))
	{
		i = 0;
		while (tetri[i].t)
		{
			tetri[i++].pos = 0;
			tetri[i++].tr = (t_uint192){0, 0, 0};
		}
		map->size++;
		map->bits = (t_uint192){0, 0, 0};
	}
	return (*map);
}

void	display_map(t_tetri *t, t_map map)
{
	t_uint192	m;
	t_cnts		c;
	char		*buff;

	throw_error(!(buff = ft_strnew(map.size * (map.size + 1))), "error");
	ft_memset(buff, '.', map.size * (map.size + 1) - 1);
	c.l = -1;
	while (t[++c.l].t)
	{
		c = (t_cnts){0, -1, 0, c.l, 0};
		move_tetri(&t[c.l].tr, t[c.l].pos, map.size);
		while (++c.p <= map.size * map.size)
		{
			m = shift_l192(&(t_uint192){0, 0, 1}, (192 - c.p));
			if (map.size > 8)
				if ((t[c.l].tr.up & m.up) != 0 || (t[c.l].tr.mi & m.mi) != 0 ||
					(t[c.l].tr.lo & m.lo) != 0)
					buff[c.p + c.t - 1] = c.l + 'A';
			if (map.size <= 8 && ((t[c.l].tr.up & m.up) != 0 ||
				(t[c.l].tr.mi & m.mi) != 0))
				buff[c.p + c.t - 1] = c.l + 'A';
			(c.p && c.p % map.size == 0) ? buff[c.p + c.t++] = '\n' : 42;
		}
	}
	ft_putstr(buff);
}
