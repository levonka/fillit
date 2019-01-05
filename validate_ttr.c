/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ttr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:42:24 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/05 11:48:11 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ПЕРЕЛОЖЕНО В FILLIT_FOR_TEST
t_ttr	*check_valid_template(char *ttr, t_ttr *tmpl)
{
	while (tmpl != NULL)
	{
		if (ft_strcmp(tmpl->template, ttr) == 0)
			return (tmpl);
		tmpl = tmpl->next;
	}
	return (NULL);
}

// ЗАФРИШИНО. В ФУНКЦИИ 26 СТРОК
char	*ttr_trim(char *ttr, int i, int k, int count)
{
	char	*ttr_true;
	char	*ttr_res;

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
	ttr_res = ft_strtrim(ttr_true);
	free(ttr_true);
	return (ttr_res);
}

// ЗАФРИШИНО. ПЕРЕЛОЖЕНО В FILLIT_FOR_TEST
char	*adjust_ttr_form_ext(char *ttr, char *ttr_fix, int i, int k)
{
	while (ttr[i] != '\0')
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
	return (ttr_trim(ttr_fix, 0, 0, 0));
}

// ФРИШИТЬ НЕЧЕГО. ПЕРЕЛОЖЕНО В FILLIT_FOR_TEST
char	*adjust_ttr_form_dispatcher(char *ttr)
{
	char	*ttr_fix;
	char	*ttr_res;

	ttr_fix = ft_strnew(17);
	if (ttr_fix == NULL)
		return (NULL);
	ttr_res = adjust_ttr_form_ext(ttr, ttr_fix, 0, 0);
	free(ttr_fix);
	return (ttr_res);	// Я ЗДЕСЬ
}

// ФРИШИТЬ НЕЧЕГО. ПЕРЕЛОЖЕНО В FILLIT_FOR_TEST
char	valid_checker(char *ttr)
{
	t_uchar	mem;

	mem = 0;
	if (ttr[0] == '\n')
		return (-1);
	while (*ttr)
	{
		if (*ttr != '.' && *ttr != '#' && *ttr != '\n')
			return (-1);
		(*ttr == '#') ? mem++ : mem;
		if (mem > 4)
			return (-1);
		ttr++;
	}
	if (mem < 4)
		return (-1);
	return (1);
}
