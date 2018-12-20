/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_templates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/20 17:22:25 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttr	*ft_create_base_ttr(char *template, char h, char w)
{
	t_ttr	*new;

	new = (t_ttr *)malloc(sizeof(t_ttr));
	ISMALLOC_CHR(new);
	ISMALLOC_CHR(template);
	new->template = template;
	new->height = h - 48;
	new->width = w - 48;
	new->next = NULL;
	return (new);
}

t_ttr		*ft_template_maker(char *templates, t_ttr **head, char *tab)
{
	t_ttr			*node;
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

// typedef struct			s_ttr
// {
// 	unsigned char		height;
// 	unsigned char		width;
// 	char				*template;
// 	unsigned char		letter;
// 	struct s_ttr		*next;
// }						t_ttr;



void		copy_ttr_list(t_ttr *tmpl, t_ttr **ttr_lst)
{

	int i;
	t_ttr *ptr;



	i = 0;
	ptr = (*ttr_lst);
	printf("ZDAROVA\n");
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	ptr = ft_create_base_ttr(tmpl->template, tmpl->height + 48, tmpl->width + 48);
	// printf("%s\n", ptr->template);
	// printf("%s\n", (*ttr_lst)->template);
	// printf("%d\n", i);
	ptr->letter = 'A' + i;

	// printf("%s\n", (ptr)->template);
	// printf("%d\n", (ptr)->width);
	// printf("%s\n", (*ttr_lst)->template);
	// printf("%s\n", (*ttr_lst)->template);

		
	



	// ISMALLOC_CHR(tmpl);
	// return (0);
}