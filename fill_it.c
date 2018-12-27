/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:26 by agottlie         ###   ########.fr       */
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
				return (-1);
			if (ft_isalpha(g_field[j + y][i + x]) && figure->template[dot] != '.')
				checker = 1;
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return ((checker == 0) ? 1 : -1);
}

int		ft_insertfigure(t_ttr *figure, int x, int y)
{
	int		i;
	int		j;
	int		dot;

	j = 0;
	dot = 0;
	// if (ft_canplace_checker(figure, x, y, mapsize) == 0)
	// 	return (-1);
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

void	ft_clearfigure(t_ttr *figure, int x, int y)
{
	int		i;
	int		j;

	i = 0;
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
	// return ((checker == 0) ? 1 : 0);
}

//	в ft_mapmaker лежит итеративный вариант функции (если нет, смотри git log (commit - "it works, but not shaffle"))
/*void	ft_rec_mapmaker(t_ttr *node, int x, int y, int mapsize, int g)
{
	if (node == NULL)
		return ;
	else if (ft_insertfigure(node, x, y, mapsize) != -1)
		ft_rec_mapmaker(node->next, 0, 0, mapsize, g);
	else if (x == mapsize && y == mapsize)
	{
		create_field(find_ttr_quantity(root), g);
		ft_rec_mapmaker(root, 0, 0, ft_strlen(g_field[0]), g + 1);
	}
	else if (x == mapsize)
		ft_rec_mapmaker(node, 0, y + 1, mapsize, g);
	else
		ft_rec_mapmaker(node, x + 1, y, mapsize, g);
}*/

int		ft_mapmaker_rec(t_ttr *node, int x, int y, int mapsize, int g)
{
	if (ft_canplace_checker(node, x, y, mapsize) != -1)	// проверить можно ли поставить фигуру
	{
		printf("beginning | x = %d, y = %d\n\n", x, y);
		ft_insertfigure(node, x, y);					// если можно, то ставим фигуру
		printf("this figure has placed\n%s\n\n", node->template);
		ft_printsplit_arr(g_field);
		if (node->next != NULL)
		{
			g = ft_mapmaker_rec(node->next, 0, 0, mapsize, g); // пробуем ставить следущую фигуру
			printf("g = %d\n", g);
			if (g == 1)
			{
				printf("everything is alright\n");
				return (8);
			}
			else if (g == -1)
			{
				printf("g = %d | return 3\n", g);
				return (3);
			}
			else if (g != 3)
			{
				printf("\ni can't place your figure\n%s\n\ngo to recursion\n\n", node->next->template);
				printf("x = %d, y = %d\n\n", x, y);
				ft_clearfigure(node, x, y);
				g = ft_mapmaker_rec(node, x + 1, y, mapsize, g);
			}
		}
		else
		{
			printf("every nodes has printed | return -1 | quit recursion\n");
			return (-1);
		}
	}
	else
	{
		if (x == mapsize && y == mapsize)				// если не получилось поставить фигуру
		{
			printf("x = mapsize && y == mapsize | return -1\n");						// удаляем фигуру
			return (5);
		}
		else if (x == mapsize)							// условие для перемещения
		{
			y++;
			x = 0;
			printf("y++ x = 0 | y = %d\n| template\n%s\n\n", y, node->template);
			g = ft_mapmaker_rec(node, x, y, mapsize, g);
		}
		else
		{
			x++;
			printf("x++ x = %d\n", x);
			g = ft_mapmaker_rec(node, x, y, mapsize, g);
		}
	}
	// printf("return %d, node =\n%s\n", g, node->template);
	printf("return %d\n", g);
	return (g);
}

// int		ft_mapmaker(t_ttr *node, int x, int y, int mapsize)
// {
	// x = 0;
	// int x2 = 0;
	// y = 0;
	// int y2 = 0;
	// t_ttr *sec_node;
	// int		i = 0;

	// while (node || sec_node)
	// {
	// 	ft_printsplit_arr(g_field);
	// 	if (ft_canplace_checker(node, x, y, mapsize) != -1)	// проверить можно ли поставить фигуру
	// 	{
	// 		ft_insertfigure(node, x, y);					// если можно, то ставим фигуру
	// 		sec_node = node;
	// 		node = node->next;
	// 		x2 = x;
	// 		y2 = y;
	// 	}
	// 	else												// иначе
	// 	{
	// 		if (x == mapsize && y == mapsize)				// если не получилось поставить
	// 		{
	// 			printf("hello\n");
	// 			ft_clearfigure(sec_node, x2, y2);			// удаляем фигуру
	// 			x = 0;
	// 			y = 0;
	// 		}
	// 		else if (x == mapsize)							// условие для перемещения
	// 		{
	// 			y++;
	// 			x = 0;
	// 		}
	// 		else
	// 			x++;
	// 	}
	// 	printf("x = %d\ny = %d\n", x, y);
	// 	i++;
	// }

	// printf("\n");
	// ft_insertfigure(node, 1, 2);
	// ft_printsplit_arr(g_field);
	// printf("\n");
	// ft_clearfigure(node, x, y);
	// ft_printsplit_arr(g_field);
	// printf("\n");
	// ft_insertfigure(node, x + 1, y);
	// ft_printsplit_arr(g_field);
	// return (0);
// }

int		ft_mapmaker_dispatcher()
{
	t_ttr	*node;
	int		len;

	node = root;
	if ((len = find_ttr_quantity(root)) == -1)
	{
		printf("list is too big\n");
		return (-1);
	}
	create_field(len, 0);
	printf("\nTHE BEGINNING ===========================\n\n");
	ft_mapmaker_rec(node, 0, 0, ft_strlen(g_field[0]), 0);
	printf("\n");
	ft_printsplit_arr(g_field);
	printf("\n");
	return (0);
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

	if (ft_mapmaker_dispatcher() == -1)
		return (-1);

	// printf("\n");
	// ft_printsplit_arr(g_field);
	// printf("\n");
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
// ft_solver("/Users/agottlie/projects/fillit/fillit_git/v2.fillit");
	return (1);
}
