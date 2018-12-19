/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/19 18:09:51 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttr	*ft_create_ttr(char *template)
{
	t_ttr	*new;

	new = (t_ttr *)malloc(sizeof(t_ttr));
	ISMALLOC_LL(new);
	if (template == NULL)
		return (NULL);

	new->template = ft_strdup(template);
	ISMALLOC_LL(new->template);
	new->next = NULL;
	return (new);
}

t_base_ttr	*ft_template_ll(char *templates)
{
	t_base_ttr		*new;
	unsigned char	i;

	i = 0;
	new = (t_base_ttr *)malloc(sizeof(t_base_ttr));
	ISMALLOC_LL(new);
	if (templates == NULL)
		return (NULL);

	while (templates[i] != '\0')
	{
		/*	НАПИСАТЬ ФУНКЦИЮ, КОТОРАЯ БУДЕТ СОЗДАВАТЬ ЛИСТ
		ИЗ 19 СТРУКТУР, В КАЖДОЙ ИЗ КОТОРЫХ БУДЕТ TEMPLATE,
		ВЫСОТА И ШИРИНА ШАБЛОНА	*/
		++i;
	}
	new->template = ft_strdup(templates);
	ISMALLOC_LL(new->template);
	new->next = NULL;
	return (new);
}

int		main()
{
	t_base_ttr	*ptr;
	char		*arr;

	arr = ft_strdup("####|#\n#\n#\n#|##\n##|##.\n.##");
	ptr = ft_template_ll(arr);
	printf("%s\n", ptr->template);


	return (0);
}