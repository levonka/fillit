/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:34:49 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/05 17:22:48 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*prev_elem;
	t_list	*new_elem;

	new_lst = NULL;
	if (lst && (*f))
	{
		new_lst = (*f)(lst);
		prev_elem = new_lst;
		lst = lst->next;
		while (lst)
		{
			new_elem = (*f)(lst);
			prev_elem->next = new_elem;
			prev_elem = new_elem;
			lst = lst->next;
		}
		prev_elem->next = NULL;
	}
	return (new_lst);
}
