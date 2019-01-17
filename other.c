/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:41:30 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/15 13:49:26 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_sqr_ttr(int n)
{
	int	x;
	int	decreased;
	int	nx;

	x = 1;
	decreased = 0;
	while (n)
	{
		nx = (x + n / x) >> 1;
		if (x == nx || (nx > x && decreased))
			break ;
		decreased = nx < x;
		x = nx;
	}
	return (x * x != n) ? ++x : x;
}

char	grab_ttr_line(int fd, t_ttr *tmpl_lst)
{
	char	*ttr_arr;
	char	*ttr_grab;
	int		ret;
	char	buff[21];
	t_ttr	*node;

	if ((ttr_grab = ft_strnew(21)) == NULL)
		return (-1);
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		ft_bzero(ttr_grab, 21);
		ft_strncpy(ttr_grab, buff, ret);
		if (valid_checker(ttr_grab) == -1)
			return (-1);
		ttr_arr = adjust_ttr_form_dispatcher(ttr_grab);
		ISMALLOC(ttr_arr);
		if ((node = check_valid_template(ttr_arr, tmpl_lst)) == NULL)
			return (-1);
		if (ttr_add_lst(node) == -1)
			return (-1);
	}
	if (ttr_grab[19] == '\n' && ttr_grab[20] == '\0')
		return (1);
	return (-1);
}

t_ttr	*check_valid_template(char *ttr, t_ttr *tmpl)
{
	while (tmpl != NULL)
	{
		if (ft_strcmp(tmpl->template, ttr) == 0)
			return (tmpl);
		tmpl = tmpl->next;
	}
	return (NULL);
}

char	*ttr_trimmer(char *ttr)
{
	int		i;
	int		j;
	char	*ttr_trimmed;

	i = 0;
	j = ft_strlen(ttr) - 1;
	while (ttr[i] != '#' && ttr[i] != '.' && ttr[i] != '\0')
		i++;
	while (j != 0 && ttr[j] != '.' && ttr[j] != '#')
		j--;
	ttr_trimmed = ft_strsubi(ttr, i, j);
	return (ttr_trimmed);
}
