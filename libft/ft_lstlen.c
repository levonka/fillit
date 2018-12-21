/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:59:05 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/05 16:01:00 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **root)
{
	size_t	len;
	t_list	*tmp;

	len = 0;
	tmp = *root;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
