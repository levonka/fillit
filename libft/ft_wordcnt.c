/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:28:21 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/05 17:26:35 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcnt(char *str)
{
	int		wc;
	int		i;

	if (*str)
	{
		i = 0;
		wc = 1;
		if (ft_checkws(str[i]))
			while (ft_checkws(str[i]))
				i++;
		while (str[i] != '\0')
		{
			if (ft_checkws(str[i]))
			{
				while (ft_checkws(str[i]))
					i++;
				wc++;
				str[i] == '\0' ? wc-- : wc;
			}
			i++;
		}
		return (wc);
	}
	return (0);
}
