/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:07:16 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/09 11:07:17 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if (!s || (tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		tmp[i] = (*f)(i, s[i]);
	return (tmp);
}
