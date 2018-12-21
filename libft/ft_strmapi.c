/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:04:50 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/06 08:59:07 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*start;
	unsigned int	i;

	if (f && s)
	{
		i = 0;
		if (!(fresh = ft_strnew(ft_strlen(s))))
			return (0);
		start = fresh;
		while (s[i] != '\0')
		{
			fresh[i] = (f)(i, s[i]);
			i++;
		}
		return (start);
	}
	return (0);
}
