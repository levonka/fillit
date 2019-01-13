/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:38:51 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/05 12:09:06 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_solver(char *file_name)
{
	char		fd;
	t_ttr		*tmpl_lst_head;
	char		*templates;
	char		*height_width;

	height_width = ft_strdup("412223233232323232322323232323233232");
	templates = ft_strnew(181);
	if (height_width == NULL || templates == NULL)
		return (-1);
	ft_strcat(templates, "#\n#\n#\n#|##\n##|##.\n.##|.##\n##.|#.\n##\n.#|");
	ft_strcat(templates, ".#\n##\n#.|##\n#.\n#.|#.\n#.\n##|##\n.#\n.#|");
	ft_strcat(templates, ".#\n.#\n##|###\n#..|###\n..#|#..\n###|..#\n###|");
	ft_strcat(templates, ".#.\n###|###\n.#.|#.\n##\n#.|.#\n##\n.#");
	if (ft_template_maker(templates, &tmpl_lst_head, height_width) == NULL)
		return (-1);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	if (grab_ttr_line(fd, tmpl_lst_head) == -1)
		return (-1);
	if (ft_mapmaker_dispatcher() == -1)
		return (-1);
	free(height_width);
	free(templates);
	ft_clear_list(tmpl_lst_head);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_solver(av[1]) == 0)
		return (0);
	else if (ac == 1)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (64);
	}
	else
		ft_putstr("error\n");
	return (1);
}
