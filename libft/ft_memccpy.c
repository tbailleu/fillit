/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:33:33 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/08 10:33:37 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sour;
	unsigned char	*dest;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sour[i];
		if (dest[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
