/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:00:19 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 10:12:07 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	throw_error(int bool, char *error_msg)
{
	if (bool)
	{
		ft_putendl(error_msg);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	int			fd;
	char		*filedata;
	t_tetri		*tetri;
	t_map		map;

	throw_error(ac > 2, "error");
	throw_error(ac < 2, ft_strjoinfree(ft_strjoin("usage: ", av[0]), " file"));
	throw_error((fd = open(av[1], O_RDONLY)) <= 0, "error");
	throw_error(!(filedata = ft_readfile(fd)), "error");
	close(fd);
	tetri = file_check(filedata);
	map = map_solver(tetri);
	display_map(tetri, map);
	return (0);
}
