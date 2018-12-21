/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:05:42 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/03 15:52:25 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_counter(int nb)
{
	int		count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_write(int len, char *str, int i, int n)
{
	while (len > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = ft_itoa_counter(n);
	if (n >= 0)
	{
		if ((str = ft_strnew(len)) == NULL)
			return (NULL);
		i = len - 1;
	}
	if (n < 0)
	{
		if ((str = ft_strnew(len + 1)) == NULL)
			return (NULL);
		if (n == -2147483648)
			return (ft_strcpy(str, "-2147483648"));
		str[0] = '-';
		n *= -1;
		i = len;
	}
	str = ft_itoa_write(len, str, i, n);
	return (str);
}
