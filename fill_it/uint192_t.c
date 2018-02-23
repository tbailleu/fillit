/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint192_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:24:30 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/24 13:13:13 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_uint192	shift_l192(t_uint192 *nb, size_t k)
{
	if (k >= 64)
	{
		nb->up = nb->mi;
		nb->mi = nb->lo;
		nb->lo = 0;
		shift_l192(nb, k - 64);
	}
	else
	{
		nb->up = (nb->up << k) | (nb->mi >> (64 - k));
		nb->mi = (nb->mi << k) | (nb->lo >> (64 - k));
		nb->lo = (nb->lo << k);
	}
	return (*nb);
}

t_uint192	shift_r192(t_uint192 *nb, size_t k)
{
	if (k >= 64)
	{
		nb->lo = nb->mi;
		nb->mi = nb->up;
		nb->up = 0;
		shift_r192(nb, k - 64);
	}
	else
	{
		nb->lo = (nb->lo >> k) | (nb->mi << (64 - k));
		nb->mi = (nb->mi >> k) | (nb->up << (64 - k));
		nb->up = (nb->up >> k);
	}
	return (*nb);
}
