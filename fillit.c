/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/14 19:39:39 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_putfigure(t_ttr *figure, char x, char y)
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

char	ft_findplace(t_ttr *node, char *x, char *y, char mapsize)
{
	while (ft_canplace_checker(node, *x, *y, mapsize) == -1)
	{
		if (*x == mapsize && *y == mapsize)
		{
			if (node == g_root)
			{
				create_field(find_ttr_quantity());
				return (6);
			}
			return (4);
		}
		else if (*x == mapsize)
		{
			*y = *y + 1;
			*x = 0;
		}
		else
			*x = *x + 1;
	}
	return (2);
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
			if (ft_isalpha(g_field[j + y][i + x]) &&
				figure->template[dot] != '.')
				return (-1);
			++dot;
			++i;
		}
		++dot;
		++j;
	}
	return (1);
}

char	ft_mapmaker(t_ttr *ptr, char x, char y, char msize)
{
	char	g;

	if (ft_canplace_checker(ptr, x, y, msize) != -1 && ft_putfigure(ptr, x, y))
		if (ptr->next != NULL && (g = ft_mapmaker(ptr->next, 0, 0, msize)))
		{
			if (g == -1)
				return (3);
			else if (g == 4)
			{
				ft_clearfigure(ptr, x, y);
				return (ft_mapmaker(ptr, x + 1, y, msize));
			}
		}
		else
			return (-1);
	else
	{
		if ((g = ft_findplace(ptr, &x, &y, msize)) == 2)
			return (ft_mapmaker(ptr, x, y, msize));
		else if (g == 6)
			ft_mapmaker(ptr, 0, 0, ft_strlen(g_field[0]));
		else if (g == 4)
			return (4);
	}
	return (g);
}

char	ft_mapmaker_dispatcher(void)
{
	t_ttr	*node;
	char	len;

	node = g_root;
	if ((len = find_ttr_quantity()) == -1)
		return (-1);
	create_field(len);
	ft_mapmaker(node, 0, 0, ft_strlen(g_field[0]));
	ft_printsplit_arr(g_field);
	return (0);
}
