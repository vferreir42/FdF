/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:54:07 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/19 12:45:18 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		freetabofint(t_str *str)
{
	int		y;
	int		x;

	y = -1;
	while (++y < str->map->sizetaby)
	{
		x = -1;
		while (++x < str->map->sizetabx)
			free(str->map->tab[y][x]);
		free(str->map->tab[y]);
	}
	free(str->map->tab);
}

int			creationtabofint(t_str *s, int y, int x)
{
	if (!(s->map->tab = malloc(sizeof(int **) * s->map->sizetaby + 1)))
		return (0);
	while (++y < s->map->sizetaby)
	{
		if (!(s->map->tab[y] = malloc(sizeof(int *) * s->map->sizetabx + 1)))
			return (0);
		x = -1;
		while (++x < s->map->sizetabx)
		{
			if (!(s->map->tab[y][x] = malloc(sizeof(int) * 3)))
				return (0);
			verifaltitude(s->map->read[y][x], y, x);
			s->map->tab[y][x][0] = atoi(s->map->read[y][x]);
			free(s->map->read[y][x]);
			s->map->tab[y][x][1] = 1;
			s->map->tab[y][x][2] = 2;
		}
		s->map->tab[y][x] = NULL;
		free(s->map->read[y]);
	}
	s->map->tab[y] = NULL;
	free(s->map->read);
	return (1);
}

static int	firstrd(char *argv)
{
	char	*line;
	int		i;
	int		fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i + 1);
}

int			readmap(t_str *str, char *argv, int fd)
{
	char	*line;
	int		i;

	if ((fd = open(argv, O_RDONLY)) == -1
			|| !(str->map->read = malloc(sizeof(char **) * firstrd(argv))))
		return (0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((str->map->read[i] = ft_strsplit(line, ' ')) == 0)
			return (0);
		free(line);
		if (i == 0)
			sizefirstline(str, str->map->read[i]);
		else if (i != 0)
			if (sizeotherline(str, str->map->read[i]) == 0)
				return (0);
		i++;
	}
	free(line);
	close(fd);
	str->map->sizetaby = i;
	if (creationtabofint(str, -1, -1) == 0)
		return (0);
	return (1);
}
