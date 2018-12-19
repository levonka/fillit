/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:12:46 by agottlie          #+#    #+#             */
/*   Updated: 2018/12/19 17:53:48 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ISMALLOC_I(s) if ((s) == NULL) return (-1)
# define ISMALLOC_LL(s) if ((s) == NULL) return (NULL)

typedef struct			s_base_ttr
{
	unsigned char		height;
	unsigned char		width;
	char				*template;
	unsigned char		quantity;
	struct s_base_ttr	*next;
}						t_base_ttr;

typedef struct		s_ttr
{
	unsigned char	height;
	unsigned char	width;
	char			*template;
	unsigned char	letter;
	struct s_ttr	*next;
}					t_ttr;

# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

#endif