/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:04:21 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/19 15:08:40 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
			break ;
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
