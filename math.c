/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:21:29 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:43:25 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_absvalue(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int		ft_comparaisonfloat(float a, float b)
{
	float	epsilon;
	float	temp;

	temp = 0;
	if (b > a)
	{
		a = temp;
		a = b;
		b = temp;
	}
	temp = a - b;
	epsilon = EPSILON;
	if (temp < epsilon)
		return (1);
	else
		return (0);
}
