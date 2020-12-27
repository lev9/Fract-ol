/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	style(int key, t_fractol *fr)
{
	char	*it;

	if (fr->type != 4)
	{
		it = ft_itoa(fr->iter);
		mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0x000000, it);
		free(it);
	}
	fr->style = key;
	if (fr->type != 1)
	{
		if (fr->style == 50 && fr->type == 3)
			fr->twist = 8.000000;
		if (fr->style == 50 && fr->type == 2)
			fr->twist = 1.000000;
		if (fr->style == 51)
			fr->twist = 1.000000;
		if (fr->style == 52)
			fr->twist = 11.000000;
	}
	get_iter(fr);
	it = ft_itoa(fr->iter);
	if (fr->type != 4)
		mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0xbdaabf, it);
	free(it);
}

void	mouse(int key, t_fractol *fr)
{
	int		n;

	n = fr->w;
	if (key == 98 || key == -1)
	{
		mlx_string_put(fr->mlx, fr->win, n + 130, 240, 0x000000, "<-");
		mlx_string_put(fr->mlx, fr->win, n + 130, 295, 0xbdaabf, "<-");
		fr->mouse = 1;
	}
	if (key == 118 || key == -2)
	{
		mlx_string_put(fr->mlx, fr->win, n + 130, 295, 0x000000, "<-");
		mlx_string_put(fr->mlx, fr->win, n + 130, 240, 0xbdaabf, "<-");
		fr->mouse = 0;
	}
}

void	reset(int key, t_fractol *fr)
{
	if (key == 114)
	{
		fr->zoom = 0.75;
		if (fr->type == 1)
		{
			fr->posx = 0;
			fr->posy = 0;
		}
		if (fr->type == 2)
		{
			fr->posx = -(fr->w / 2) / (0.5 * fr->zoom * fr->w) / 2;
			fr->posy = 0;
		}
		if (fr->type == 3)
		{
			fr->zoom = 0.50;
			fr->posx = 0;
			fr->posy = 0;
		}
	}
	if (key == 99)
	{
		fr->cx = -0.7;
		fr->cy = 0.27015;
	}
}

void	iterate(int key, t_fractol *fr)
{
	int		i;
	char	*it;

	it = ft_itoa(fr->iter);
	mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0x000000, it);
	free(it);
	if (key == 65361 || key == 65363)
		i = 1;
	if (key == 103 || key == 104)
		i = 10;
	if (key == 106 || key == 107)
		i = 100;
	if ((key == 65361 || key == 103 || key == 106) && fr->iter >= i)
		fr->iter -= i;
	if (key == 65363 || key == 104 || key == 107)
		fr->iter += i;
	it = ft_itoa(fr->iter);
	mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0xbdaabf, it);
	free(it);
}

void	move(int key, t_fractol *fr)
{
	if (key == 119)
		fr->posy -= 0.04 / fr->zoom;
	if (key == 115)
		fr->posy += 0.04 / fr->zoom;
	if (key == 97)
		fr->posx -= 0.04 / fr->zoom;
	if (key == 100)
		fr->posx += 0.04 / fr->zoom;
}
