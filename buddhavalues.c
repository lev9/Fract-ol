/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhavalues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	minim(t_fractol *fr)
{
	if (fr->style == 49)
		fr->min = 1000;
	else if (fr->style == 50)
		fr->min = 1000;
	else if (fr->style == 51)
		fr->min = 3;
	else if (fr->style == 52)
		fr->min = 2000;
	else if (fr->style == 53)
		fr->min = 100;
	else if (fr->style == 54)
		fr->min = 2970;
}

void	maxim(t_fractol *fr)
{
	if (fr->style == 49)
		fr->max = 10000;
	else if (fr->style == 50)
		fr->max = 15000;
	else if (fr->style == 51)
		fr->max = 60;
	else if (fr->style == 52)
		fr->max = 6000;
	else if (fr->style == 53)
		fr->max = 1000;
	else if (fr->style == 54)
		fr->max = 3000;
}

void	get_spots(t_fractol *fr)
{
	if (fr->style == 49)
		fr->spots = 20000000;
	else if (fr->style == 50)
		fr->spots = 30000000;
	else if (fr->style == 51)
		fr->spots = 20000000;
	else if (fr->style == 52)
		fr->spots = 40000000;
	else if (fr->style == 53)
		fr->spots = 10000000;
	else if (fr->style == 54)
		fr->spots = 100000000;
}

void	get_zoom(int style, t_fractol *fr)
{
	if (style == 49)
		fr->zoom = 1.0;
	else if (style == 50)
		fr->zoom = 1.0;
	else if (style == 51)
		fr->zoom = 12.0;
	else if (style == 52)
		fr->zoom = 1.0;
	else if (style == 53)
		fr->zoom = 1.0;
	else if (style == 54)
		fr->zoom = 1.0;
	fr->value = 1200;
	if (fr->style == 51)
		fr->value = fr->w + 200;
}

void	get_random(int count, t_fractol *fr)
{
	int	i;

	i = fr->spots / 4;
	if (fr->style == 53)
	{
		fr->randy = rand() % 1000;
		fr->randx = rand() % 1000;
	}
	else
	{
		fr->randy = rand() % 10000;
		fr->randx = rand() % 10000;
	}
	if ((count > i && count < i * 2) || (count > i * 3 && count < i * 4))
		fr->randx = -fr->randx;
	if ((count > i * 2 && count < i * 3) || (count > i * 3 && count < i * 4))
		fr->randy = -fr->randy;
}
