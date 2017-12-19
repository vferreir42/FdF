/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:03 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:52:29 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		sizeotherline(t_str *str, char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != str->map->sizetabx)
	{
		ft_putstr("The size of each line are not equal\n");
		return (0);
	}
	else
		return (1);
}

void	sizefirstline(t_str *str, char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	str->map->sizetabx = i;
}

void	verifaltitude(char *str, int y, int x)
{
	int	i;

	y = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9')
				&& str[i] != '-' && str[i] != '+')
		{
			ft_putstr("Altitude is not good in line ");
			ft_putnbr(y + 2);
			ft_putstr(", column ");
			ft_putnbr(x + 1);
			ft_putstr(", set to 0.\n");
		}
		i++;
	}
}
