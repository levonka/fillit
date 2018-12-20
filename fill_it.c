/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/20 17:20:26 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_field;

int		find_sqr(int n)
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

int		valid_checker(char *ttr)
{
	int mem;

	mem = 0;
	if (ttr[19] != '\n' || ttr[0] == '\n')
		return (0);
	while (*ttr)
	{
		if (*ttr != '.' && *ttr != '#' && *ttr != '\n')
			return (0);
		(*ttr == '#') ? mem++ : mem;
		if (mem > 4)
			return (0);
		ttr++;
	}
	if (mem < 4)
		return (0);
	return (1);
}

char	*ttr_trim(char *ttr)
{
	char *ttr_true;
	int i;
	int k;
	int count;

	i = 0;
	k = 0;
	count = 0;
	ttr_true = ft_strnew(16);

	while (ttr[i] != '\0')
	{
		if (i == 0 || ttr[i - 1] == '\n')
		{
			while(ttr[i] == '.' && ttr[i] != '\n')
			{
				count++;
				i++;
				if (ttr[i] == '#')
					{
						i = i - count;
						break ;
					}
			}
		}
		count = 0;
		ttr_true[k] = ttr[i];
		k++;
		i++;
	}
	ttr_true = ft_strtrim(ttr_true);
	return (ttr_true);
}

char	*adjust_form(char *ttr)
{
	int i;
	int k;
	char *ttr_true;
	char *ttr_fix;

	ttr_fix = ft_strnew(16);
	i = 0;
	k = 0;
	while (ttr[i] != '\0')
	{
		if (i < 5 && ttr[i] == '.' && ttr[i + 5] == '.' && ttr[i + 10] == '.' && ttr[i + 15] == '.')
		{
			ttr[i] = '!';
			ttr[i + 5] = '!';
			ttr[i + 10] = '!';
			ttr[i + 15] = '!';
			i++;
		}
		else 
		{
			while (ttr[i] == '!')
				i++;
			ttr_fix[k] = ttr[i];
			k++;
			i++;
		}
	}
	return (ttr_trim(ttr_fix));
}

int		check_valid_template(char *ttr, t_ttr *head, t_ttr **ttr_list)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		if (ft_strcmp(head->template, ttr) == 0)
		{
			copy_ttr_list(head, ttr_list);
			return (1);
		}
		head = head->next;
	}
	return (-1);
}


char	grab_ttr_line(int fd, t_ttr *tmpl_lst, t_ttr **ttr_lst)
{
	char *ttr_arr;
	char *ttr_grab;
	int n;
	char buff[21];

	ttr_grab = ft_strnew(21);

	while ((n = read(fd, buff, 21)))
	{
		buff[n] = '\0';
		ft_strncpy(ttr_grab, buff, 21);
		if (!valid_checker(ttr_grab))
			return (-1);	
		ttr_arr = adjust_form(ttr_grab);
		if (check_valid_template(ttr_arr, tmpl_lst, ttr_lst) == -1)
			return (-1);

		
		
		ft_bzero(ttr_grab, 21);
		break ;
	}
	return (0);
}



void	create_field(int ttr, int exp)
{
	int x;
	int i;
	int j;

	i = -1;
	x = find_sqr(ttr * 4);
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
	char 		*line;
	char 		*figure;
	int 		ttr;
	t_ttr		*tmpl_lst;
	char		*templates;
	char		*tab;
	t_ttr 		*ttr_lst;

	tab = ft_strdup("412223233232323232322323232323233232");
	templates = ft_strdup("#\n#\n#\n#|##\n##|##.\n.##|.##\n##.|#.\n##\n.#|\
.#\n##\n#.|##\n#.\n#.|#.\n#.\n##|##\n.#\n.#|.#\n.#\n##|###\n#..|\
###\n..#|#..\n###|..#\n###|.#.\n###|###\n.#.|#.\n##\n#.|.#\n##\n.#");

	ft_template_maker(templates, &tmpl_lst, tab);

	ttr = 0;
	fd = open("valid_ex02.fillit", O_RDONLY);

	ttr_lst = malloc(sizeof(t_ttr));
	ttr_lst = NULL;

	grab_ttr_line(fd, tmpl_lst, &ttr_lst);

	// printf("templ %s\n", tmpl_lst->template);
	// printf("height %d\n", tmpl_lst->height);
	// printf("width %d\n", tmpl_lst->width);
	// printf("letter %c\n", tmpl_lst->letter);

	// printf("templ %s\n", ttr_lst->template);
	// printf("height %d\n", ttr_lst->height);
	// printf("width %d\n", ttr_lst->width);
	// printf("letter %c\n", ttr_lst->letter);


	return (0);
}






// int		main()
// {
// 	t_base_ttr	*head;
// 	char		*templates;
// 	char		*tab;

// 	tab = ft_strdup("412223233232323232322323232323233232");

// 	templates = ft_strdup("#\n#\n#\n#|##\n##|##.\n.##|.##\n##.|#.\n##\n.#|\
// .#\n##\n#.|##\n#.\n#.|#.\n#.\n##|##\n.#\n.#|.#\n.#\n##|###\n#..|\
// ###\n..#|#..\n###|..#\n###|.#.\n###|###\n.#.|#.\n##\n#.|.#\n##\n.#");

// 	ft_template_maker(templates, &head, tab);
// 	while (head != NULL)
// 	{
// 		printf("%s", head->template);
// 		printf("%d", head->width);
// 		printf("%d\n\n", head->height);
// 		head = head->next;
// 	}
// 	return (0);
// }