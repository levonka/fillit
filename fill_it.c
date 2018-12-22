/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/22 10:18:36 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_field;
t_ttr	*root;

t_ttr	*check_valid_template(char *ttr, t_ttr *tmpl)
{
	int i;

	i = 0;
	while (tmpl != NULL)
	{
		if (ft_strcmp(tmpl->template, ttr) == 0)
			return (tmpl);
		tmpl = tmpl->next;
	}
	return (0);
}


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
	printf("x is %d\n", x);

	exp != 0 ? (x += exp) : x;


	g_field = (char **)malloc(sizeof(char *) * x + 1);
	// bzero(g_field, (x + 1));
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
 	printf("Minimal square is:\n\n");
	ft_printsplit_arr(g_field);
 	printf(("\n%d x %d:\n"), x, x);

}

int		main(void)
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

	fd = open("valid_ex02.fillit", O_RDONLY);


	grab_ttr_line(fd, tmpl_lst);

	while(root)
	{
		printf("%s\n", root->template);
		printf("%d\n", root->height);
		printf("%c\n", root->letter);
		printf("%d\n\n", root->width);
		root = root->next;
	}

	return (0);
}
