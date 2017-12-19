/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:57:47 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/19 12:48:46 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		linkedpoint(t_str *str, float ybis, float xbis)
{
	float		coefy;
	float		coefx;
	float		i;
	float		y;
	float		x;

	y = str->map->tab[str->map->cnty][str->map->cntx][1];
	x = str->map->tab[str->map->cnty][str->map->cntx][2];
	if (ft_absvalue(xbis - x) > ft_absvalue(ybis - y))
		i = ft_absvalue(xbis - x);
	else
		i = ft_absvalue(ybis - y);
	coefx = (xbis - x) / i;
	coefy = (ybis - y) / i;
	while (i > 0)
	{
		ft_put_pixel(str, x, y);
		x += coefx;
		y += coefy;
		i--;
	}
}

void			displayelse(t_str *str)
{
	str->mlx->couleur = 0x33E3FF;
	if (str->map->tab[str->map->cnty][str->map->cntx + 1])
	{
		if ((str->map->tab[str->map->cnty][str->map->cntx][0] > 0)
				|| (str->map->tab[str->map->cnty][str->map->cntx + 1][0] > 0))
			str->mlx->couleur = 0x096A09;
		linkedpoint(str, str->map->tab[str->map->cnty][str->map->cntx + 1][1],
				str->map->tab[str->map->cnty][str->map->cntx + 1][2]);
	}
	str->mlx->couleur = 0x33E3FF;
	if (str->map->tab[str->map->cnty + 1])
	{
		if ((str->map->tab[str->map->cnty][str->map->cntx][0] > 0)
				|| (str->map->tab[str->map->cnty + 1][str->map->cntx][0] > 0))
			str->mlx->couleur = 0x096A09;
		linkedpoint(str, str->map->tab[str->map->cnty + 1][str->map->cntx][1],
				str->map->tab[str->map->cnty + 1][str->map->cntx][2]);
	}
}

int				display(t_str *str)
{
	str->map->cnty = -1;
	while (str->map->tab[++str->map->cnty])
	{
		str->map->cntx = -1;
		while (str->map->tab[str->map->cnty][++str->map->cntx])
			if (str->mlx->justpoint == 1)
				ft_put_pixel(str,
						str->map->tab[str->map->cnty][str->map->cntx][2],
						str->map->tab[str->map->cnty][str->map->cntx][1]);
			else
				displayelse(str);
	}
	mlx_put_image_to_window(str->mlx->mlx, str->mlx->win, str->mlx->img, 0, 0);
	return (0);
}

static void		first(t_str *str)
{
	str->mlx->projection = 1;
	str->map->coef = 0.5;
	str->map->beginy = 50;
	str->map->largeur = 980 / (str->map->sizetaby - 1);
	if (str->map->largeur * (str->map->sizetabx - 1) > 1920)
		str->map->largeur = 1920 / (str->map->sizetabx - 1);
	str->map->beginx = 960 - (str->map->sizetabx - 1) * str->map->largeur / 2;
	transformationparallele(str);
	display(str);
}

int				main(int argc, char **argv)
{
	t_str str;

	if (!(str.map = malloc(sizeof(t_map)))
			|| !(str.mlx = malloc(sizeof(t_mlx)))
			|| argc != 2
			|| readmap(&str, argv[1], 0) == 0)
		return (0);
	initialisationmlx(&str);
	first(&str);
	mlx_key_hook(str.mlx->win, &my_key_funct, &str);
	mlx_loop(str.mlx->mlx);
	return (0);
}
