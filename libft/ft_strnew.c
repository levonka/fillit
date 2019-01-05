/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:00:51 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/01/05 11:59:57 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_arr;

	new_arr = (char *)malloc(sizeof(char) * (size + 1));
	if (new_arr == NULL)
		return (NULL);
	ft_bzero(new_arr, size);
	new_arr[size] = '\0';
	return (new_arr);
}
