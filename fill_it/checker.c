/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:08:36 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 13:36:47 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint16_t	tetri_type(uint16_t tetri)
{
	int				i;
	static uint16_t	masks[] = {34952, 61440, 17600, 57856, 51328, 36352, \
		35008, 11776, 50240, 59392, 52224, 27648, 35904, 58368, 35968, 19968, \
		19520, 50688, 19584, 0};

	while ((tetri & 34952) == 0)
		tetri <<= 1;
	while ((tetri & 61440) == 0)
		tetri <<= 4;
	i = 0;
	while (i < 20 && tetri != masks[i])
		i++;
	return (masks[i]);
}

uint16_t	tetri_check(uint16_t tetri)
{
	int			i;
	int			link;

	i = 0;
	link = 0;
	while (i < 16 && link != 8)
	{
		while (((uint16_t)(tetri << i) & 32768) == 0)
			i++;
		if (i >= 16)
			break ;
		if (i >= 4 && ((uint16_t)(tetri << (i - 4)) & 32768))
			link++;
		if (i < 12 && ((uint16_t)(tetri << (i + 4)) & 32768))
			link++;
		if (i % 4 != 0 && ((uint16_t)(tetri << (i - 1)) & 32768))
			link++;
		if (i % 4 != 3 && ((uint16_t)(tetri << (i + 1)) & 32768))
			link++;
		i++;
	}
	if (link == 6 || link == 8)
		return (tetri_type(tetri));
	return (0);
}

t_tetri		*file_check(char *s)
{
	t_tetri		*t;
	t_cnts		c;

	c = (t_cnts){0, 0, 0, 0, 0};
	throw_error(!(t = (t_tetri *)ft_memalloc(sizeof(*t) * 27)), "error");
	while (s[c.i])
	{
		(s[c.i] == '.') ? c.p++ : 42;
		(s[c.i] == '#') ? t[c.t].t |= 1 << (16 - ++c.d - c.p) : 42;
		if (s[c.i] == '\n')
		{
			c.l++;
			throw_error(((c.p + c.d) == 16 && c.l % 5 != 4) ||
			((s[c.i - 1] != '\n' && !c.p && !c.d) || (c.p + c.d) % 4 != 0) ||
			(s[c.i - 1] == '\n' && s[c.i + 1] == '\0'), "error");
		}
		throw_error(s[c.i] != '.' && s[c.i] != '#' && s[c.i] != '\n', "error");
		throw_error(c.t >= 26 || ((c.l != 0 && c.l % 5 == 4) && ((c.p != 12 ||
			c.d != 4) || (!(t[c.t].t = tetri_check(t[c.t].t))))), "error");
		(c.l != 0 && c.l % 5 == 4) ? c = (t_cnts){c.i, 0, 0, c.l, c.t + 1} : c;
		t[c.t].pos = 0;
		c.i++;
	}
	throw_error((c.p + c.d) % 16 != 0 || s[c.i - 1] != '\n', "error");
	return (t);
}
