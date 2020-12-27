/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *fr)
{
	if (fr->zoom > -0.015 && fr->zoom < -0.001)
		fr->zoom = 0.015;
	if (fr->zoom < 0.001)
		fr->zoom /= 1.1;
	else
		fr->zoom *= 1.1;
}

void	zoom_out(t_fractol *fr)
{
	if (fr->zoom < 0.015 && fr->zoom > 0.001)
		fr->zoom = -0.015;
	if (fr->zoom < 0.001)
		fr->zoom *= 1.1;
	else
		fr->zoom /= 1.1;
}

int		zoomer(int button, int x, int y, t_fractol *fr)
{
	if (button == 1)
	{
		fr->posx += (x - fr->w / 2) / (0.5 * fr->zoom * fr->w);
		fr->posy += (y - fr->h / 2) / (0.5 * fr->zoom * fr->h);
	}
	if (button == 4)
		zoom_in(fr);
	if (button == 5)
		zoom_out(fr);
	return (0);
}
