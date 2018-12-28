/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/28 12:39:08 by agottlie         ###   ########.fr       */
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

void	create_field(char ttr)
{
	char		x;
	int			i;
	int			j;
	static int	exp;

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
	exp++;
 	// printf("Minimal square is:\n\n");
	// ft_printsplit_arr(g_field);
 	// printf(("\n%d x %d:\n"), x, x);

}

char	ft_canplace_checker(t_ttr *figure, char x, char y, char mapsize)
{
	int		i;
	int		j;
	int		dot;

	j = 0;
	dot = 0;
	while (j < figure->height)
	{
		i = 0;
		while (i < figure->width)
		{
			if (j + y >= mapsize || i + x >= mapsize)
				return (-1);
			if (ft_isalpha(g_field[j + y][i + x]) && figure->template[dot] != '.')
				return (-1);
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return (1);
}

char	ft_insertfigure(t_ttr *figure, char x, char y)
{
	int		i;
	int		j;
	int		dot;

	j = 0;
	dot = 0;
	while (j < figure->height)
	{
		i = 0;
		while (i < figure->width && g_field[j][i] != '\0')
		{
			if (figure->template[dot] != '.')
				g_field[j + y][i + x] = figure->letter;
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return (1);
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

void	ft_clearmap(char **g_field)			//	ДОДЕЛАТЬ ЧТОБ НОРМАЛЬНО ФРИШИЛО
{
	int		j;
	char	mapsize;

	j = 0;
	mapsize = ft_strlen(g_field[0]);
	printf("%d\n", mapsize);
	while (j <= mapsize)
	{
		free(g_field[j]);
		++j;
	}
}

char	ft_findplace(t_ttr *node, char *x, char *y, char mapsize)
{
	while (ft_canplace_checker(node, *x, *y, mapsize) == -1)
	{
		if (*x == mapsize && *y == mapsize)
		{
			if (node == root)
				return (6);					//	6 если не удалось поставить первую фигуру. В таком случае надо менять размер карты
			return (4);						//	4 когда надо откатиться на один назад
		}
		else if (*x == mapsize)
		{
			*y = *y + 1;
			*x = 0;
		}
		else
			*x = *x + 1;
	}
	return (2);						//	2 если фигуру удалось поставить. В таком случае надо повторить рекурсию и поставить фигуру.
}

char	ft_mapmaker_rec(t_ttr *node, char x, char y, char mapsize, char g)
{
	char	answ;

	if (ft_canplace_checker(node, x, y, mapsize) != -1)	// проверить можно ли поставить фигуру
	{
		// printf("beginning | x = %d, y = %d\n\n", x, y);
		ft_insertfigure(node, x, y);					// если можно, то ставим фигуру
		// printf("this figure has placed\n\n%s\n\n", node->template);
		// ft_printsplit_arr(g_field);
		// printf("\n");
		if (node->next != NULL)
		{
			g = ft_mapmaker_rec(node->next, 0, 0, mapsize, g); // пробуем ставить следущую фигуру
			// printf("\ng = %d\n", g);
			if (g == 1)
			{
				// printf("everything is alright\n");
				return (8);
			}
			else if (g == -1)
			{
				return (3);
			}
			else if (g != 3)
			{
				// printf("\ni can't place your figure\n%s\n\ngo to recursion\n\n", node->next->template);
				// printf("x = %d, y = %d\n\n", x, y);
				ft_clearfigure(node, x, y);
				return (ft_mapmaker_rec(node, x + 1, y, mapsize, g));
			}
		}
		else
		{
			// printf("every nodes has printed | return -1 | quit recursion\n");
			return (-1);
		}
	}
	else
	{
		if ((answ = ft_findplace(node, &x, &y, mapsize)) == 2)
			return (ft_mapmaker_rec(node, x, y, mapsize, g));
		else if (answ == 4)
		{
			// printf("delaem otkat | return 5\n");
			return (5);
		}
		else if (answ == 6)
		{
			// printf("ne udalos postavit pervuyu figuru | otkat\n");
			create_field(find_ttr_quantity(root));
			// mapsize = ft_strlen(g_field[0]);
			return (ft_mapmaker_rec(node, 0, 0, ft_strlen(g_field[0]), 0));	//	вероятно можно удалить
		}
	}
	// printf("return %d, node =\n%s\n", g, node->template);
	// printf("r-%d ", g);
	return (g);
}

char	ft_mapmaker_dispatcher()
{
	t_ttr	*node;
	char	len;

	node = root;
	if ((len = find_ttr_quantity(root)) == -1)
	{
		printf("list is too big\n");
		return (-1);
	}
	create_field(len);
	// printf("\nTHE BEGINNING ===========================\n\n");
	ft_mapmaker_rec(node, 0, 0, ft_strlen(g_field[0]), 0);
	printf("\n");
	ft_printsplit_arr(g_field);
	printf("\n");
	return (0);
}

char	ft_solver(char *file_name)
{
	char 		fd;
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
