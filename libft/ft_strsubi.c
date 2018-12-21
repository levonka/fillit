/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:14:55 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/20 15:15:17 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubi(char const *s, unsigned int start, unsigned int end)
{
	char	*new_arr;
	char	*fresh;

	fresh = (char *)malloc((end - start) + 2);
	if (fresh == NULL)
		return (NULL);
	new_arr = fresh;
	while (s[start] != '\0' && start <= end)
		*(fresh++) = s[start++];
	*fresh = '\0';
	return (new_arr);
}
