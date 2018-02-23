/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:04:16 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 13:13:10 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# define BUFF_SIZE 32

typedef struct	s_uint192
{
	uint64_t	up;
	uint64_t	mi;
	uint64_t	lo;
}				t_uint192;

typedef struct	s_tetri
{
	uint16_t	t;
	t_uint192	tr;
	int			pos;
}				t_tetri;

typedef struct	s_map
{
	uint8_t		size;
	t_uint192	bits;
}				t_map;

typedef struct	s_cnts
{
	int			i;
	int			p;
	int			d;
	int			l;
	int			t;
}				t_cnts;

int				main(int argc, char **argv);
char			*ft_readfile(const int fd);
void			throw_error(int bool, char *error_msg);
t_tetri			*file_check(char *str);
uint16_t		tetri_type(uint16_t tetri);
uint16_t		tetri_check(uint16_t tetri);
t_map			*map_new(int size);
int				move_tetri(t_uint192 *tr, int pos, size_t ms);
int				place_tetri(t_map *map, int pos, t_tetri *t);
void			remove_tetri(t_map *map, int pos, t_tetri *t);
t_uint192		tetri_to_map(size_t ms, t_tetri *t);
t_uint192		is_placeable_tetri(t_map *map, int pos, t_tetri *t);
int				map_solved(t_map *map, t_tetri *tetri);
t_map			map_solver(t_tetri *tetri);
void			display_map(t_tetri *tetri, t_map map);
t_uint192		shift_l192(t_uint192 *nb, size_t k);
t_uint192		shift_r192(t_uint192 *nb, size_t k);
#endif
