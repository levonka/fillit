/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:22 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/19 16:26:54 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct		s_base_ttr
{
	unsigned char	height;
	unsigned char	width;
	char			*template;
	unsigned char	quantity;
	s_base_ttr		*next;
}					t_base_ttr;

typedef struct		s_ttr
{
	unsigned char	height;
	unsigned char	width;
	char			*template;
	unsigned char	letter;
	s_ttr			*next;
}					t_ttr;

t_ttr	ft_create_ttr()
{
	t_ttr	*new_struct;

	new_struct = (t_ttr)malloc(sizeof(t_ttr));
	ISMALLOC(new_struct);
}

int		main()
{
	t_ttr	*ptr;

	ptr = ft_create_ttr();
}