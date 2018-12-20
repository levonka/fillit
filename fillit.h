/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:19:52 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/20 16:29:48 by yharwyn-         ###   ########.fr       */
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
void					copy_ttr_list(t_ttr *head, t_ttr **ttr_lst);


#endif