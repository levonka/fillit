/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:02:44 by agottlie          #+#    #+#             */
/*   Updated: 2019/01/05 11:47:15 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_field(char ttr)
{
	char		x;
	int			i;
	int			j;
	static int	expn;

	if (expn > 0)
		ft_clearmap(g_field);
	i = -1;
	x = find_sqr_ttr(ttr * 4);
	expn != 0 ? (x += expn) : x;
	g_field = (char **)malloc(sizeof(char *) * (x + 1));
	while (++i < x)
		g_field[i] = (char*)malloc(sizeof(char) * (x + 1));
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < x)
			g_field[i][j] = '.';
		g_field[i][j] = '\0';
	}
	g_field[i] = 0;
	expn++;
}
