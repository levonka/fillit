/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:37:36 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/13 10:30:43 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (0);
	if (!(fresh = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < len)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
