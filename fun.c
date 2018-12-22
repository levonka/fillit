/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:41:30 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/22 10:31:47 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_sqr_ttr(int n)
{
	int x = 1;
	int decreased = 0;
	int nx;

	while (n) {
		nx = (x + n / x) >> 1;
		if (x == nx || (nx > x && decreased))	break;
		decreased = nx < x;
		x = nx;
	}
	return (x * x != n) ? ++x : x;
}
