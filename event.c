/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:39:56 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:25:04 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		paralleleoriso(t_str *str, int keycode)
{
	if (keycode == 34)
	{
		str->mlx->justpoint = 0;
		eveniso(str);
	}
	if (keycode == 35)
	{
		str->mlx->justpoint = 0;
		evenparalle(str);
	}
}

static void		justpoint(t_str *str)
{
	str->mlx->justpoint = 1;
	ft_clean_img(str);
	display(str);
}

static void		exitfdf(t_str *str)
{
	freetabofint(str);
	exit(0);
}

int				my_key_funct(int keycode, t_str *str)
{
	if (keycode == 53)
		exitfdf(str);
	if (keycode == 34 || keycode == 35)
		paralleleoriso(str, keycode);
	if (keycode == 65)
		justpoint(str);
	if (keycode == 69 || keycode == 78)
		evenlargeur(str, keycode);
	if (keycode == 88 || keycode == 92)
		evenaltitude(str, keycode);
	if (keycode >= 123 && keycode <= 126)
		eventfleche(str, keycode);
	return (0);
}
