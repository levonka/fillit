/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/20 15:09:36 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_base_ttr	*ft_create_base_ttr(char *template, char h, char w)
{
	t_base_ttr	*new;

	new = (t_base_ttr *)malloc(sizeof(t_base_ttr));
	ISMALLOC_CHR(new);
	ISMALLOC_CHR(template);
	new->template = template;
	new->height = h - 48;
	new->width = w - 48;
	new->next = NULL;
	return (new);
}

t_base_ttr		*ft_template_maker(char *templates, t_base_ttr **head, char *tab)
{
	t_base_ttr		*node;
	unsigned char	i;
	unsigned char	hw;
	unsigned char	len;

	i = -1;
	hw = 0;
	ISMALLOC_CHR(templates);
	node = ft_create_base_ttr("####", '1', '4');
	*head = node;
	while (templates[++i] != '\0')
	{
		len = 0;
		while (templates[i] != '|' && templates[i] != '\0')
		{
			++len;
			++i;
		}
		node->next = ft_create_base_ttr(ft_strsubi(templates, i - len, i - 1),\
tab[hw], tab[hw + 1]);
		ISMALLOC_CHR(node);
		node = node->next;
		hw += 2;
	}
	return (*head);
}