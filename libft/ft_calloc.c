/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:56:57 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/21 13:45:17 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void *ptr;

	if (!nelem || !elsize)
	{
		nelem = 1;
		elsize = 1;
	}
	ptr = ft_memalloc(nelem * elsize);
	return (ptr);
}
