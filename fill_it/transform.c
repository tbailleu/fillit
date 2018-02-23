/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:37:37 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 18:55:21 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			move_tetri(t_uint192 *tr, int pos, size_t ms)
{
	t_uint192	mask;
	size_t		i;

	mask = shift_l192(&(t_uint192){0, 0, 1}, (192 - ms * (ms - 1)));
	if (mask.lo-- == 0)
		(mask.mi-- == 0) ? mask.up-- : 42;
	while ((size_t)pos >= ms)
	{
		if (((tr->up & mask.up) | (tr->mi & mask.mi) | (tr->lo & mask.lo)) != 0)
			return (0);
		shift_r192(tr, ms);
		pos -= ms;
	}
	mask = (t_uint192){0, 0, 0};
	i = 0;
	while (i++ < ms)
	{
		mask.lo |= 1;
		shift_l192(&mask, ms);
	}
	shift_l192(&mask, 192 - ms * (ms + 1));
	while (pos-- && ((tr->lo & mask.lo) | (tr->mi & mask.mi) |
		(tr->up & mask.up)) == 0)
		shift_r192(tr, 1);
	return (pos == -1);
}

t_uint192	tetri_to_map(size_t ms, t_tetri *t)
{
	t_uint192	tr;

	tr = (t_uint192){0, 0, 0};
	if (ms == 2)
		tr.up = 0xF000000000000000;
	else if (ms == 3)
		tr.up = ((uint64_t)((t->t & 0xE0) | (t->t & 0xE00) >> 1 |
		(t->t & 0xE000) >> 2) << 50);
	else if (ms <= 8)
		tr.up = ((uint64_t)(t->t & 0xF000) << (ms * ms - 16) |
			(uint64_t)(t->t & 0xF00) << (ms * (ms - 1) - 12) |
			(uint64_t)(t->t & 0xF0) << (ms * (ms - 2) - 8) |
			(uint64_t)(t->t & 0xF) << (ms * (ms - 3) - 4))
				<< (64 - ms * ms);
	else if (ms > 8)
		tr.up = ((uint64_t)(t->t & 0xF000) << (64 - 0 * ms - 16) |
			(uint64_t)(t->t & 0xF00) << (64 - 1 * ms - 12) |
			(uint64_t)(t->t & 0xF0) << (64 - 2 * ms - 8) |
			(uint64_t)(t->t & 0xF) << (64 - 3 * ms - 4));
	return (tr);
}

t_uint192	is_placeable_tetri(t_map *map, int pos, t_tetri *t)
{
	t_uint192	tr;
	size_t		ms;

	ms = map->size;
	t->tr = tetri_to_map(ms, t);
	tr = t->tr;
	if (ms == 2 && t->t == 0xcc00)
		return (tr);
	if (ms == 3 && (t->t & 0x111F) == 0 && move_tetri(&tr, pos, ms) &&
		(tr.up & map->bits.up) == 0)
		return (tr);
	if (ms > 3 && move_tetri(&tr, pos, ms) &&
		((tr.up & map->bits.up) | (tr.mi & map->bits.mi) |
		(tr.lo & map->bits.lo)) == 0)
		return (tr);
	return ((t_uint192){0, 0, 0});
}

int			place_tetri(t_map *map, int pos, t_tetri *t)
{
	t_uint192 tr;

	tr = is_placeable_tetri(map, pos, t);
	if (tr.lo != 0 || tr.mi != 0 || tr.up != 0)
	{
		t->pos = pos;
		map->bits.up |= tr.up;
		map->bits.mi |= tr.mi;
		map->bits.lo |= tr.lo;
		return (1);
	}
	return (0);
}

void		remove_tetri(t_map *map, int pos, t_tetri *t)
{
	t_uint192	tr;

	t->tr = tetri_to_map(map->size, t);
	tr = t->tr;
	move_tetri(&tr, pos, map->size);
	map->bits.up ^= tr.up;
	map->bits.mi ^= tr.mi;
	map->bits.lo ^= tr.lo;
}
