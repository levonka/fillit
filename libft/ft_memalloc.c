/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:28:10 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/03 12:18:51 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*memory;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if ((memory = (void *)malloc(size)) && size)
	{
		ptr = memory;
		while (i < size)
		{
			*ptr++ = 0;
			i++;
		}
		return (memory);
	}
	return (NULL);
}
