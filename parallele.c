/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallele.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:47:08 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:47:16 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	placementpixeltabpar(t_str *str)
{
	int	y;
	int	x;

	y = 0;
	while (y < str->map->sizetaby)
	{
		x = 0;
		while (x < str->map->sizetabx)
		{
			str->map->tab[y][x][1] = str->map->beginy + (str->map->largeur * y);
			str->map->tab[y][x][2] = str->map->beginx + (str->map->largeur * x);
			x++;
		}
		y++;
	}
}

void	transformationparallele(t_str *str)
{
	int	y;
	int	x;

	placementpixeltabpar(str);
	y = 0;
	while (y < str->map->sizetaby)
	{
		x = 0;
		while (x < str->map->sizetabx)
		{
			if (str->map->tab[y][x][0] > 0)
			{
				str->map->tab[y][x][1] = str->map->tab[y][x][1]
					- (str->map->coef / 2) * str->map->tab[y][x][0]
					* (str->map->largeur / 10);
				str->map->tab[y][x][2] = str->map->tab[y][x][2]
					+ (str->map->coef) * str->map->tab[y][x][0]
					* (str->map->largeur / 10);
			}
			x++;
		}
		y++;
	}
}
