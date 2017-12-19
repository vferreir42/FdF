/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:27:20 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/19 12:49:05 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/includes/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define EPSILON 1
# define DEP 50

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	char	*data;
	void	*img;
	int		couleur;
	int		endian;
	int		bpp;
	int		size_line;
	int		projection;
	int		justpoint;
}				t_mlx;

typedef struct	s_map
{
	char	***read;
	int		***tab;
	int		sizetaby;
	int		sizetabx;
	int		largeur;
	int		beginy;
	int		beginx;
	float	coef;
	int		cntx;
	int		cnty;
}				t_map;

typedef struct	s_str
{
	t_map	*map;
	t_mlx	*mlx;
}				t_str;

void			verifaltitude(char *str, int y, int x);
int				my_key_funct(int keycode, t_str *str);
void			evenparalle(t_str *str);
void			eveniso(t_str *str);
void			evenaltitude(t_str *str, int keycode);
void			evenlargeur(t_str *str, int keycode);
void			eventfleche(t_str *str, int keycode);
int				display(t_str *str);
void			ft_clean_img(t_str *str);
int				initialisationmlx(t_str *str);
void			transformationiso(t_str *str);
void			transformationparallele(t_str *str);
void			freetabofint(t_str *str);
int				readmap(t_str *str, char *argv, int fd);
int				comparaisonfloat(float a, float b);
float			ft_absvalue(float a);
void			ft_put_pixel(t_str *str, int x, int y);
int				creationtabofint(t_str *str, int y, int x);
void			sizefirstline(t_str *str, char **line);
int				sizeotherline(t_str *str, char **line);

#endif
