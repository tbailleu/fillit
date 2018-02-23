/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:36:35 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/08 11:36:36 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int d;
	int s;

	d = ft_strlen(dst);
	s = 0;
	while (src[s])
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dst);
}
