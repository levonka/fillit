/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_fill_it.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:43:57 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/21 08:44:25 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#

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

// void		check_connections(char *str)
// {
// 	printf("work? %s\n", str);
// }

int		check_connections(char **str, int y, int x)
{
	if (y - 1 < 0)
	{
		if (str[y][x] == str[y][x + 1] || str[y][x] == str[y][x - 1] || str[y][x] == str[y + 1][x])
			return (1);
	}
	if (x - 1 < 0)
	{
		if (str[y][x] == str[y][x + 1] || str[y][x] == str[y + 1][x] || str[y][x] == str[y - 1][x])
			return (1);
	}
	if (x + 1 > 3)
	{
		if (str[y][x] == str[y][x - 1] || str[y][x] == str[y + 1][x] || str[y][x] == str[y - 1][x])
			return (1);
	}
	if (y + 1 > 3)
	{
		if (str[y][x] == str[y][x + 1] || str[y][x] == str[y][x - 1] || str[y][x] == str[y - 1][x])
			return (1);
	}
	else
	{
		if (str[y][x] == str[y][x + 1] || str[y][x] == str[y][x - 1] || str[y][x] == str[y + 1][x] || str[y][x] == str[y - 1][x])
			return (1);
	}
	return (0);
}


void		validate_form(char **ttr)
{
	int y;
	int x;
	int val;

	y = 0;
	x = 0;
	val = 0;
	printf("Example Tetrimino:\n");
	ft_printsplit_arr(ttr);

	while (y < 4)
	{
		// printf("(x|y) (%d,%d)\n", y, x);
		x = 0;
		while (x < 4)
		{
			if (ttr[y][x] == '#')
			{
				// printf("true or not %d\n",check_connections(ttr, y, x));
				check_connections(ttr, y, x) ? val += 1 : val;
				// printf("%d\n", val);
				// y = 4;
				// x = 4;
			}
			x++;
		}
		y++;
	}
	val >= 4 ? printf("VALID\n") : printf("NOT VALID\n");;
	// printf("total validate counts is: %d\n", val);
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

char	**grab_ttr(int fd)
{
	char	**ttr_arr;
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;

	ttr_arr = (char **)malloc(sizeof(char *) * 4 + 1);
	while (++i < 4)
		ttr_arr[i] = (char *)malloc(sizeof(char) * 4 + 1);
	ttr_arr[i] = 0;

	i = 0;

	// get_next_line(fd, &ttr_arr[i]);
	while (get_next_line(fd, &ttr_arr[i]))
	{
		if (k == 3)
		{
			k = 0;
			i++;
			break;
		}
		i++;
		k++;
	}
	ttr_arr[i] = 0;
	validate_form(ttr_arr);

	// ft_printsplit_arr(ttr_arr);
	// printf("%s\n", ttr_arr[2]);
	return (0);

}

char	grab_ttr_line(int fd)
{
	char **ttr_arr;
	char *line;
	char *ttr_grab;
	int n;
	char buff[21];

	ttr_grab = ft_strnew(21);

	// n = read(fd, buff, 21);
	// buff[n] = '\0';
	// ft_strncpy(ttr_grab, buff, 19);
	// printf("%s\n", ttr_grab);

	// n = read(fd, buff, 21);
	// buff[n] = '\0';
	// ft_strncpy(ttr_grab, buff, 19);
	// printf("%s\n", ttr_grab);

	// n = read(fd, buff, 21);
	// buff[n] = '\0';
	// ft_strncpy(ttr_grab, buff, 19);
	// printf("%s\n", ttr_grab);

	while ((n = read(fd, buff, 21)))
	{
		ft_strncpy(ttr_grab, buff, 19);
		printf("\n\n%s\n\n", ttr_grab);
		ft_bzero(ttr_grab, 19);
	}

	// while (n = read(fd, buff, 20))
	// {
	// 	ft_strncpy(ttr_grab, &line, 4);
	// }
	// get_next_line(fd, &line);
	// ft_strncpy(ttr_example, line, 4);

	return (0);

	// if ((n = read(fd, buff, BUFF_SIZE)) < 0)

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
	int fd;
	char *line;
	char *figure;
	int ttr;

	ttr = 0;
	fd = open("valid_ex02.fillit", O_RDONLY);

//	FIND QUANTITY OF TETRIMINOS

	// printf("%d\n", find_quantity_ttr(fd));
	grab_ttr_line(fd);

	// while (get_next_line(fd, &line))
	// 	ft_strlen(line) <= 1 ? ttr += 1 : ttr;
	// printf("TTR's %d\n", ttr);

//	GRAB TETRIMINO

	
	
	// create_field(10, 0);

	return (0);
}


// a = (int**)malloc(n * sizeof(int*));
//   // Ввод элементов массива
//   for (i = 0; i<n; i++)  // цикл по строкам
//   {
//     // Выделение памяти под хранение строк
//     a[i] = (int*)malloc(m * sizeof(int));
//     for (j = 0; j<m; j++)  // цикл по столбцам
//     {
//       printf("a[%d][%d] = ", i, j);
//       scanf("%d", &a[i][j]);
//     }
//   }