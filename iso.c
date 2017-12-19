/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:31:50 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:39:54 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		transformationiso(t_str *str)
{
	int y;
	int x;

	y = -1;
	while (str->map->tab[++y])
	{
		x = -1;
		while (str->map->tab[y][++x])
		{
			str->map->tab[y][x][1] = str->map->beginy
				+ (x + y) * str->map->largeur;
			str->map->tab[y][x][2] = str->map->beginx
				+ (x - y) * str->map->largeur;
			if (str->map->tab[y][x][0] > 0)
			{
				str->map->tab[y][x][1] -= str->map->tab[y][x][0]
					+ (str->map->coef / 4) * str->map->largeur
					* str->map->tab[y][x][0];
				str->map->tab[y][x][2] += (str->map->coef / 4)
					* str->map->largeur;
			}
		}
	}
}
