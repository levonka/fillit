/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:04:52 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/19 13:58:46 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wc(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		wc++;
	while (s[++i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			wc++;
	}
	return (wc);
}

static int	ft_sizestr(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void	ft_cleanup_split(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wc(s, c) + 1))))
		return (NULL);
	j = 0;
	i = -1;
	while (++i < ft_wc(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (!(arr[i] = ft_strsub(s, j, ft_sizestr(s + j, c))))
		{
			ft_cleanup_split(arr, i);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	arr[i] = NULL;
	return (arr);
}
