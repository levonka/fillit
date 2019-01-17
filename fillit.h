/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:19:52 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/15 13:50:28 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define ISMALLOC(s) if ((s) == NULL) return (-1)

typedef unsigned char	t_uchar;

typedef struct			s_ttr
{
	t_uchar				height;
	t_uchar				width;
	char				*template;
	t_uchar				letter;
	struct s_ttr		*next;
}						t_ttr;

char					**g_field;
t_ttr					*g_root;

int						find_ttr_quantity(void);
t_ttr					*ft_create_ttr(char *template, char h, char w);
char					ttr_add_lst(t_ttr *ptr);
t_ttr					*ft_template_maker(char *templates, t_ttr **head,
char *tab);
void					ft_clearfigure(t_ttr *figure, char x, char y);

int						find_sqr_ttr(int n);
char					grab_ttr_line(int fd, t_ttr *tmpl_lst);
void					ft_clear_list(t_ttr *head);
t_ttr					*check_valid_template(char *ttr, t_ttr *tmpl);
char					*ttr_trimmer(char *ttr);

char					valid_checker(char *ttr);
char					*ttr_trim(char *ttr, int i, int k, int count);
char					*adjust_ttr_form_ext(char *ttr, char *ttr_fix,
int i, int k);
char					*adjust_ttr_form_dispatcher(char *ttr);
int						valid_checker_ext(char *ttr);

void					create_field(char ttr);
char					ft_canplace_checker(t_ttr *figure, char x, char y,
char mapsize);
char					ft_putfigure(t_ttr *figure, char x, char y);
char					ft_findplace(t_ttr *node, char *x, char *y,
char mapsize);
char					ft_mapmaker(t_ttr *node, char x, char y, char mapsize);
char					ft_mapmaker_dispatcher(void);

char					ft_solver(char *file_name);

#endif
