/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:05 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/01 16:58:29 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*src;
	unsigned char	*dst;
	int				i;

	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	i = 0;
	while (src[i] != '\0' || dst[i] != '\0')
	{
		if (src[i] != dst[i])
			return (src[i] - dst[i]);
		i++;
	}
	return (0);
}
