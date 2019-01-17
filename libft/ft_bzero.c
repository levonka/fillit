/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:37:18 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/14 16:01:31 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t length)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)str;
	i = 0;
	while (i < length)
	{
		s[i] = '\0';
		i++;
	}
}
