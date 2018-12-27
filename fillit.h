/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:19:52 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/25 12:21:39 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define ISMALLOC_I(s) if ((s) == NULL) return (-1)
# define ISMALLOC_CHR(s) if ((s) == NULL) return (NULL)


typedef struct			s_ttr
{
	unsigned char		height;
	unsigned char		width;
	char				*template;
	unsigned char		letter;
	struct s_ttr		*next;
}						t_ttr;

t_ttr					*ft_create_ttr(char *template, char h, char w);
t_ttr					*ft_template_maker(char *templates, t_ttr **head, char *tab);
t_ttr					*copy_ttr_list(t_ttr *head, t_ttr **ttr_lst);
int						find_sqr_ttr(int n);
int						find_quantity_ttr(int fd);
int						valid_checker(char *ttr);
char					*ttr_trim(char *ttr, int i, int k, int count);
char					*adjust_ttr_form(char *ttr);
char					*adjust_ttr_form_ext(char *ttr, char *ttr_fix, int i, int k);
void					ttr_add_lst(t_ttr **begin_list, t_ttr *ptr);
t_ttr					*check_valid_template(char *ttr, t_ttr *tmpl);
int					 	find_ttr_quantity(t_ttr *root);

#endif

