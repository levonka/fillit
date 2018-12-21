/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:03:16 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/11/25 16:50:48 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*largestr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	largestr = (char *)haystack;
	len = ft_strlen(needle);
	if (len == 0)
		return (largestr);
	while (largestr[i] != '\0')
	{
		if (largestr[i] == needle[j])
		{
			while (largestr[i++] == needle[j++])
				if (j == len)
					return (&largestr[i - j]);
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (0);
}
