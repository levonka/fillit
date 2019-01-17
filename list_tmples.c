/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tmples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/15 13:49:48 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_ttr_quantity(void)
{
	t_ttr	*ptr;
	int		i;

	if (g_root)
	{
		i = 0;
		ptr = g_root;
		while (ptr)
		{
			ptr = ptr->next;
			i++;
		}
		return ((i < 27) ? i : -1);
	}
	else
		return (-1);
}

char	ttr_add_lst(t_ttr *ptr)
{
	t_ttr	*tmp;
	int		i;

	i = 0;
	if (g_root)
	{
		tmp = g_root;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = ft_create_ttr(ptr->template,
			ptr->height + 48, ptr->width + 48);
		ISMALLOC(tmp->next);
		tmp->next->letter = 'B' + i;
	}
	else
	{
		g_root = ft_create_ttr(ptr->template,
			ptr->height + 48, ptr->width + 48);
		ISMALLOC(g_root);
		g_root->letter = 'A';
	}
	return (0);
}

t_ttr	*ft_create_ttr(char *template, char h, char w)
{
	t_ttr	*ptr;

	ptr = (t_ttr *)malloc(sizeof(t_ttr));
	if (ptr == NULL)
		return (NULL);
	ptr->template = template;
	ptr->height = h - 48;
	ptr->width = w - 48;
	ptr->next = NULL;
	return (ptr);
}

t_ttr	*ft_template_maker(char *templates, t_ttr **head, char *tab)
{
	t_ttr	*node;
	t_uchar	i;
	t_uchar	hw;
	t_uchar	len;

	i = -1;
	hw = 0;
	if ((node = ft_create_ttr("####", '1', '4')) == NULL)
		return (NULL);
	*head = node;
	while (templates[++i] != '\0')
	{
		len = 0;
		while (templates[i] != '|' && templates[i] != '\0')
		{
			++len;
			++i;
		}
		if ((node->next = ft_create_ttr(ft_strsubi(templates, i - len, i - 1),\
tab[hw], tab[hw + 1])) == NULL)
			return (NULL);
		node = node->next;
		hw += 2;
	}
	return (*head);
}

void	ft_clearfigure(t_ttr *figure, char x, char y)
{
	char	i;
	char	j;

	j = 0;
	while (j < figure->height)
	{
		i = 0;
		while (i < figure->width)
		{
			if (g_field[j + y][i + x] == figure->letter)
				g_field[j + y][i + x] = '.';
			++i;
		}
		++j;
	}
}
