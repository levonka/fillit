/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:47:41 by yharwyn-          #+#    #+#             */
/*   Updated: 2018/12/03 15:53:08 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_cyan(void)
{
	write(1, "\e[36;1m", 8);
}

static void	ft_putchar_magenta(void)
{
	write(1, "\e[35;1m", 8);
}

static void	ft_putchar_yellow(void)
{
	write(1, "\e[33;1m", 8);
}

void		ft_colorize_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i == 3 ? i = 0 : i;
		i == 0 ? ft_putchar_cyan() : i;
		i == 2 ? ft_putchar_yellow() : i;
		i == 1 ? ft_putchar_magenta() : i;
		ft_putchar(ft_toupper(*str));
		str++;
		i++;
	}
	ft_putchar('\n');
}
