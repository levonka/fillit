/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:07:17 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/03 12:39:54 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		len;
	size_t		dst_len;

	d = dst;
	s = src;
	len = size;
	while (len-- != 0 && *d != '\0')
		d++;
	dst_len = d - dst;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (len != 1)
		{
			*d++ = *s;
			len--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
