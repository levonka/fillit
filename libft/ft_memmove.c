/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:04:20 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/03 16:01:26 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_new;
	unsigned char	*src_new;
	size_t			i;

	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	i = -1;
	if (src_new < dst_new)
		while (len-- > 0)
			dst_new[len] = src_new[len];
	else
		while (++i < len)
			dst_new[i] = src_new[i];
	return (dst_new);
}
