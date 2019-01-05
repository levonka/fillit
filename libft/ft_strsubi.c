/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:14:55 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/05 11:50:25 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubi(char const *s, unsigned int start, unsigned int end)
{
	char	*fresh;
	int		i;

	i = 0;
	fresh = (char *)malloc((end - start) + 2);
	if (fresh == NULL)
		return (NULL);
	while (s[start] != '\0' && start <= end)
	{
		fresh[i] = s[start++];
		++i;
	}
	fresh[i] = '\0';
	return (fresh);
}
