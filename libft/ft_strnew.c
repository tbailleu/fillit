/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:50:01 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/08 10:50:02 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = (char *)ft_memalloc(size + 1);
	if (!tmp)
		return (NULL);
	return (tmp);
}
