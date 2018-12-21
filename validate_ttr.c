/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ttr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:42:24 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/21 10:00:22 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_checker(char *ttr)
{
	int		mem;

	mem = 0;
	if (ttr[19] != '\n' || ttr[0] == '\n')
		return (0);
	while (*ttr)
	{
		if (*ttr != '.' && *ttr != '#' && *ttr != '\n')
			return (0);
		(*ttr == '#') ? mem++ : mem;
		if (mem > 4)
			return (0);
		ttr++;
	}
	if (mem < 4)
		return (0);
	return (1);
}

char	*ttr_trim(char *ttr, int i, int k, int count)
{
	char	*ttr_true;

	ttr_true = ft_strnew(16);
	while (ttr[i] != '\0')
	{
		if (i == 0 || ttr[i - 1] == '\n')
		{
			while (ttr[i] == '.' && ttr[i] != '\n')
			{
				count++;
				i++;
				if (ttr[i] == '#')
				{
					i = i - count;
					break ;
				}
			}
		}
		count = 0;
		ttr_true[k] = ttr[i];
		k++;
		i++;
	}
	ttr_true = ft_strtrim(ttr_true);
	return (ttr_true);
}

char	*adjust_ttr_form_ext(char *ttr, char *ttr_fix, int i, int k)
{
	int		count;

	while (ttr[i] != '\0')
	{
		if (i < 5 && ttr[i] == '.' && ttr[i + 5] == '.'
		&& ttr[i + 10] == '.' && ttr[i + 15] == '.')
		{
			ttr[i] = '!';
			ttr[i + 5] = '!';
			ttr[i + 10] = '!';
			ttr[i + 15] = '!';
			i++;
		}
		else
		{
			while (ttr[i] == '!')
				i++;
			ttr_fix[k++] = ttr[i++];
		}
	}
	i = 0;
	k = 0;
	count = 0;
	return (ttr_trim(ttr_fix, i, k, count));
}

char	*adjust_ttr_form(char *ttr)
{
	int		i;
	int		k;
	char	*ttr_fix;

	ttr_fix = ft_strnew(16);
	i = 0;
	k = 0;
	return (adjust_ttr_form_ext(ttr, ttr_fix, i, k));
}
