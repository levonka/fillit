/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_templates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/21 15:12:43 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttr	*ft_create_ttr(char *template, char h, char w)
{
	t_ttr	*ptr;

	if (!(ptr = malloc(sizeof(t_list))))
		return (NULL);
	ptr->template = template;
	ptr->height = h - 48;
	ptr->width = w - 48;
	ptr->next = NULL;
	return (ptr);
}

void	ttr_add_lst(t_ttr **root, t_ttr *ptr)
{
	t_ttr	*tmp;
	int		i;

	i = 0;
	if (root && *root)
	{
		tmp = *root;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = ft_create_ttr(ptr->template,
			ptr->height + 48, ptr->width + 48);
		tmp->next->letter = 'B' + i;
	}
	else
	{
		*root = ft_create_ttr(ptr->template, ptr->height + 48, ptr->width + 48);
		(*root)->letter = 'A';
	}
}

t_ttr	*ft_template_maker(char *templates, t_ttr **head, char *tab)
{
	t_ttr			*node;
	unsigned char	i;
	unsigned char	hw;
	unsigned char	len;

	i = -1;
	hw = 0;
	ISMALLOC_CHR(templates);
	node = ft_create_ttr("####", '1', '4');
	*head = node;
	while (templates[++i] != '\0')
	{
		len = 0;
		while (templates[i] != '|' && templates[i] != '\0')
		{
			++len;
			++i;
		}
		node->next = ft_create_ttr(ft_strsubi(templates, i - len, i - 1),\
tab[hw], tab[hw + 1]);
		ISMALLOC_CHR(node);
		node = node->next;
		hw += 2;
	}
	return (*head);
}
