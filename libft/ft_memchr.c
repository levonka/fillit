/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:22:01 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/01 15:41:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	target;

	i = 0;
	str = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == target)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
