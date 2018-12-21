/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:19:52 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/20 15:07:06 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define ISMALLOC_I(s) if ((s) == NULL) return (-1)
# define ISMALLOC_CHR(s) if ((s) == NULL) return (NULL)

typedef struct			s_base_ttr
{
	unsigned char		height;
	unsigned char		width;
	char				*template;
	struct s_base_ttr	*next;
}						t_base_ttr;

typedef struct			s_ttr
{
	unsigned char		height;
	unsigned char		width;
	char				*template;
	unsigned char		letter;
	struct s_ttr		*next;
}						t_ttr;

t_ttr					*ft_create_ttr(char *template, char h, char w);
t_base_ttr				*ft_template_maker(char *templates, t_base_ttr **head, char *tab);


#endif