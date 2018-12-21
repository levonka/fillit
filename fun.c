/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:41:30 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/21 08:54:37 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_sqr_ttr(int n)
{
	int x = 1;
	int decreased = 0;
	int nx;

	while (n) {
		int nx = (x + n / x) >> 1;
		if (x == nx || (nx > x && decreased))	break;
		decreased = nx < x;
		x = nx;
	}
	return (x * x != n) ? ++x : x;
}

int		find_quantity_ttr(int fd)
{
	char *line;
	int ttr;

	ttr = 0;
	while (get_next_line(fd, &line))
		ft_strlen(line) <= 1 ? ttr += 1 : ttr;
	return (ttr + 1);
}
