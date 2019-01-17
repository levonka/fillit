/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ttr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:42:24 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/15 13:50:05 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ttr_trim(char *ttr, int i, int k, int count)
{
	char	*ttr_true;

	ttr_true = ft_strnew(16);
	if (ttr_true == NULL)
		return (NULL);
	while (ttr[i] != '\0')
	{
		if (i == 0 || ttr[i - 1] == '\n')
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
		count = 0;
		ttr_true[k++] = ttr[i++];
	}
	return (ttr_trimmer(ttr_true));
}

char	*adjust_ttr_form_ext(char *ttr, char *ttr_fix, int i, int k)
{
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
	return (ttr_trim(ttr_fix, 0, 0, 0));
}

char	*adjust_ttr_form_dispatcher(char *ttr)
{
	char	*ttr_fix;
	char	*ttr_res;

	ttr_fix = ft_strnew(17);
	if (ttr_fix == NULL)
		return (NULL);
	ttr_res = adjust_ttr_form_ext(ttr, ttr_fix, 0, 0);
	return (ttr_res);
}

int		valid_checker_ext(char *ttr)
{
	while (*ttr != '\n' && *ttr != '\0')
	{
		if (*ttr == '.')
		{
			while (*ttr != '\n' && *ttr != '\0')
			{
				if (*ttr == '#')
					return (-1);
				ttr++;
			}
			break ;
		}
		ttr++;
		if (*ttr == '\0')
			break ;
	}
	return (0);
}

char	valid_checker(char *ttr)
{
	t_uchar mem;

	mem = 0;
	if (ttr[0] == '\n')
		return (-1);
	while (*ttr)
	{
		if (*ttr != '.' && *ttr != '#' && *ttr != '\n')
			return (-1);
		(*ttr == '.') ? mem++ : mem;
		if ((*ttr == '#') && (valid_checker_ext(ttr) == -1))
			return (-1);
		ttr++;
	}
	if (mem != 12)
		return (-1);
	return (1);
}
