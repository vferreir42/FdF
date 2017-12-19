/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:44:57 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:30:48 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	evenparalle(t_str *str)
{
	str->mlx->projection = 1;
	str->map->coef = 0.5;
	str->map->beginy = 50;
	str->map->largeur = 980 / (str->map->sizetaby - 1);
	if (str->map->largeur * (str->map->sizetabx - 1) > 1920)
		str->map->largeur = 1920 / (str->map->sizetabx - 1);
	str->map->beginx = 960 - (str->map->sizetabx - 1) * str->map->largeur / 2;
	transformationparallele(str);
	ft_clean_img(str);
	display(str);
}

void	eveniso(t_str *str)
{
	str->map->coef = 0.5;
	str->mlx->projection = 2;
	str->map->beginy = 50;
	str->map->largeur = 980 / (str->map->sizetabx + str->map->sizetaby - 2);
	if ((str->map->sizetabx + str->map->sizetaby - 2) *
			str->map->largeur > 1920)
		str->map->largeur = 1920 /
			(str->map->sizetabx + str->map->sizetaby - 2);
	str->map->beginx = 960 - (str->map->sizetabx + str->map->sizetaby - 2)
			* (str->map->largeur / 2)
			+ (str->map->sizetaby - 1) * str->map->largeur;
	transformationiso(str);
	ft_clean_img(str);
	display(str);
}

void	evenaltitude(t_str *str, int keycode)
{
	if (keycode == 88)
		str->map->coef += 0.5;
	if (keycode == 92)
		str->map->coef -= 0.5;
	if (str->mlx->projection == 1)
		transformationparallele(str);
	else
		transformationiso(str);
	ft_clean_img(str);
	display(str);
}

void	evenlargeur(t_str *str, int keycode)
{
	if (keycode == 69)
		str->map->largeur += 1;
	if (keycode == 78)
		str->map->largeur -= 1;
	if (str->mlx->projection == 1)
		transformationparallele(str);
	else
		transformationiso(str);
	ft_clean_img(str);
	display(str);
}

void	eventfleche(t_str *str, int keycode)
{
	str->map->cnty = -1;
	while (++str->map->cnty < str->map->sizetaby)
	{
		str->map->cntx = -1;
		while (++str->map->cntx < str->map->sizetabx)
			if (keycode == 124)
				str->map->tab[str->map->cnty][str->map->cntx][2] += DEP;
			else if (keycode == 123)
				str->map->tab[str->map->cnty][str->map->cntx][2] -= DEP;
			else if (keycode == 125)
				str->map->tab[str->map->cnty][str->map->cntx][1] += DEP;
			else if (keycode == 126)
				str->map->tab[str->map->cnty][str->map->cntx][1] -= DEP;
	}
	if (keycode == 124)
		str->map->beginx += DEP;
	else if (keycode == 123)
		str->map->beginx -= DEP;
	else if (keycode == 125)
		str->map->beginy += DEP;
	else if (keycode == 126)
		str->map->beginy -= DEP;
	ft_clean_img(str);
	display(str);
}
