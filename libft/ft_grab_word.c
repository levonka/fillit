/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:47:48 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/05 17:28:12 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_grab_word(char *str, int pos)
{
	int		start;
	int		finish;
	int		i;
	char	*word;

	start = -1;
	finish = -1;
	i = 0;
	while (*str && (finish == -1 || start == -1))
	{
		if (start == -1)
		{
			ft_checkws(str[pos + i]) ? start = pos + i + 1 : start;
			(i + pos <= 0) ? start = 0 : i--;
			(start >= 0) ? i = 0 : i;
		}
		else
		{
			ft_checkws(str[pos + i]) ? finish = pos + i - 1 : finish;
			i++;
		}
	}
	word = ft_strsub(str, start, (finish - start + 1));
	return (word);
}
