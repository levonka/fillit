/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:29:59 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/06 09:04:57 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*start;

	if (f && s)
	{
		if (!(fresh = ft_strnew(ft_strlen(s))))
			return (0);
		start = fresh;
		while (*s)
			*fresh++ = (f)(*s++);
		*fresh = '\0';
		return (start);
	}
	return (0);
}
