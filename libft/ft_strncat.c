/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:41:00 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/08 11:41:02 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, int nb)
{
	int d;
	int s;

	d = ft_strlen(dst);
	s = 0;
	while (src[s] && s < nb)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dst);
}
