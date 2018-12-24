/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/24 18:04:41 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_field;
t_ttr	*root;

char	grab_ttr_line(int fd, t_ttr *tmpl_lst)
{
	char *ttr_arr;
	char *ttr_grab;
	int n;
	char buff[21];
	t_ttr *ptr;

	ttr_grab = ft_strnew(21);
	while ((n = read(fd, buff, 21)))
	{
		buff[n] = '\0';
		ft_strncpy(ttr_grab, buff, 21);
		if (!valid_checker(ttr_grab))
			return (-1);
		ttr_arr = adjust_ttr_form(ttr_grab);
		if (!(ptr = check_valid_template(ttr_arr, tmpl_lst)))
			return (-1);
		ttr_add_lst(&root, ptr);
		ft_bzero(ttr_grab, 21);
	}
	return (0);
}

void	create_field(int ttr, int exp)
{
	int x;
	int i;
	int j;

	i = -1;
	x = find_sqr_ttr(ttr * 4);
	// printf("x is %d\n", x);
	exp != 0 ? (x += exp) : x;
	g_field = (char **)malloc(sizeof(char *) * x + 1);
	while (++i < x)
		g_field[i] = (char*)malloc(sizeof(char) * x + 1);
	j = -1;
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < x)
			g_field[i][j] = '.';
		g_field[i][j] = '\0';
	}
	g_field[i] = 0;
 	// printf("Minimal square is:\n\n");
	// ft_printsplit_arr(g_field);
 	// printf(("\n%d x %d:\n"), x, x);

}

int		ft_canplace_checker(t_ttr *figure, int x, int y, int mapsize)
{
	int		i;
	int		j;
	int		dot;
	int		checker;

	i = 0;
	j = 0;
	dot = 0;
	checker = 0;
	while (j < figure->height)
	{
		i = 0;
		while (i < figure->width)
		{
			if (j + y >= mapsize || i + x >= mapsize)
				return (0);
			if (ft_isalpha(g_field[j + y][i + x]) && figure->template[dot] != '.')
				checker = 1;
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return ((checker == 0) ? 1 : 0);
}

int		ft_insertshape(t_ttr *figure, int x, int y, int mapsize)
{
	int		i;
	int		j;
	int		dot;

	j = 0;
	dot = 0;
	if (ft_canplace_checker(figure, x, y, mapsize) == 0)
		return (-1);
	while (j < figure->height)
	{
		i = 0;
		while (i < figure->width && g_field[j][i] != '\0')
		{
			if (figure->template[dot] != '.' && !ft_isalpha(g_field[j + y][i + x]))
				g_field[j + y][i + x] = figure->letter;
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return (1);
}

//	в ft_mapmaker лежит итеративный вариант функции
void	ft_rec_mapmaker(t_ttr *node, int x, int y, int mapsize, int g)
{
	if (node == NULL)
		return ;
	else if (ft_insertshape(node, x, y, mapsize) != -1)
		return (ft_rec_mapmaker(node->next, 0, 0, mapsize, g));
	else if (x == mapsize && y == mapsize)
	{
		create_field(find_ttr_quantity(&root), g);
		return (ft_rec_mapmaker(root, 0, 0, ft_strlen(g_field[0]), g + 1));
	}
	else if (x == mapsize)
		return (ft_rec_mapmaker(node, 0, y + 1, mapsize, g));
	else
		return (ft_rec_mapmaker(node, x + 1, y, mapsize, g));
}

void	ft_mapmaker()
{
	t_ttr	*node;

	node = root;
	create_field(find_ttr_quantity(&root), 0);
	ft_rec_mapmaker(node, 0, 0, ft_strlen(g_field[0]), 1);
	// while (node)
	// {
	// 	if (ft_insertshape(node, x, y, mapsize) != -1)
	// 	{
	// 		printf("\n%s\n", node->template);
	// 		node = node->next;
	// 		x = 0;
	// 		y = 0;
	// 	}
	// 	else if (x == mapsize && y == mapsize)
	// 	{
	// 		++g;
	// 		create_field(find_ttr_quantity(&root), g);
	// 		mapsize = ft_strlen(g_field[0]);
	// 		x = 0;
	// 		y = 0;
	// 		node = root;
	// 		printf("g%d\n", g);
	// 	}
	// 	else if (x == mapsize)
	// 	{
	// 		x = 0;
	// 		y++;
	// 	}
	// 	else
	// 		x++;
	// 	// printf("i%d\n", i);
	// 	++i;
	// }
}

int		ft_solver(char *file_name)
{
	int 		fd;
	t_ttr		*tmpl_lst;
	char		*templates;
	char		*tab;

	tab = ft_strdup("412223233232323232322323232323233232");
	templates = ft_strdup("#\n#\n#\n#|##\n##|##.\n.##|.##\n##.|#.\n##\n.#|\
.#\n##\n#.|##\n#.\n#.|#.\n#.\n##|##\n.#\n.#|.#\n.#\n##|###\n#..|\
###\n..#|#..\n###|..#\n###|.#.\n###|###\n.#.|#.\n##\n#.|.#\n##\n.#");

	tmpl_lst = ft_template_maker(templates, &tmpl_lst, tab);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	if (grab_ttr_line(fd, tmpl_lst) == -1)
		return (-1);

	ft_mapmaker();

	printf("\n");
	ft_printsplit_arr(g_field);
	printf("\n");
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
