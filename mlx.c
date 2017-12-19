/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:59:00 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:45:43 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_img(t_str *str)
{
	free(str->mlx->data);
	str->mlx->img = mlx_new_image(str->mlx->mlx, 1920, 1080);
	str->mlx->data = mlx_get_data_addr(str->mlx->img,
			&str->mlx->bpp, &str->mlx->size_line, &str->mlx->endian);
}

void	ft_put_pixel(t_str *str, int x, int y)
{
	int	r;
	int	g;
	int	b;

	if (y > 1079 || y < 0 || x < 0 || x > 1919)
		return ;
	r = (str->mlx->couleur & 16711680) >> 16;
	g = (str->mlx->couleur & 65280) >> 8;
	b = (str->mlx->couleur & 255);
	str->mlx->data[y * str->mlx->size_line + x * str->mlx->bpp / 8] = b;
	str->mlx->data[y * str->mlx->size_line + x * str->mlx->bpp / 8 + 1] = g;
	str->mlx->data[y * str->mlx->size_line + x * str->mlx->bpp / 8 + 2] = r;
}

int		initialisationmlx(t_str *str)
{
	str->mlx->couleur = 0x096A09;
	str->mlx->justpoint = 0;
	str->mlx->mlx = mlx_init();
	str->mlx->win = mlx_new_window(str->mlx->mlx, 1920, 1080, "mlx_42");
	str->mlx->img = mlx_new_image(str->mlx->mlx, 1920, 1080);
	str->mlx->data = mlx_get_data_addr(str->mlx->img,
			&str->mlx->bpp, &str->mlx->size_line, &str->mlx->endian);
	return (0);
}
