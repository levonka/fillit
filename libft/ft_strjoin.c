/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:56:10 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/13 09:02:49 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		if (!(fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		while (*s1)
			fresh[i++] = *s1++;
		while (*s2)
			fresh[i++] = *s2++;
		fresh[i] = '\0';
		return (fresh);
	}
	return (0);
}
