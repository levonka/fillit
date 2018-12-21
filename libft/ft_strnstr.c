/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:46:21 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/05 08:47:34 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*largestr;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	largestr = (char *)haystack;
	length = ft_strlen(needle);
	if (length == 0)
		return (largestr);
	while (largestr[i] != '\0' && len-- > 0)
	{
		if (largestr[i] == needle[j])
		{
			while ((largestr[i++] == needle[j++]) && ((int)len-- >= 0))
				if (j == length)
					return (&largestr[i - j]);
			i = i - j;
			len = len + j;
			j = 0;
		}
		i++;
	}
	return (0);
}
