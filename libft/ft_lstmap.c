/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:49:29 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/10 11:49:31 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || (tmp = f(lst)) == NULL)
		return (NULL);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if ((tmp->next = f(lst)) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
