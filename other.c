/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:41:30 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/05 11:45:48 by agottlie         ###   ########.fr       */
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
	t_ttr	*head;

	if ((ttr_grab = ft_strnew(21)) == NULL)
		return (-1);
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		ft_strncpy(ttr_grab, buff, 21);
		if (valid_checker(ttr_grab) == -1)
			return (-1);
		ttr_arr = adjust_ttr_form_dispatcher(ttr_grab);
		if (ttr_arr == NULL)
			return (-1);
		if ((head = check_valid_template(ttr_arr, tmpl_lst)) == NULL)
			return (-1);
		if (ttr_add_lst(&g_root, head) == -1)
			return (-1);
		ft_bzero(ttr_grab, 21);
		free(ttr_arr);
	}
	free(ttr_grab);
	return (0);
}

void	ft_clear_list(t_ttr *head)
{
	t_ttr	*ptr;
	t_ttr	*ptr_next;

	ptr = head;
	ptr_next = ptr->next;
	free(ptr);
	while (ptr_next != NULL)
	{
		ptr = ptr_next;
		ptr_next = ptr->next;
		free(ptr->template);
		free(ptr);
	}
}

void	ft_clearmap(char **g_field)
{
	int		mapsize;

	mapsize = ft_strlen(g_field[0]);
	while (mapsize >= 0)
	{
		free(g_field[mapsize]);
		--mapsize;
	}
	free(g_field);
}
