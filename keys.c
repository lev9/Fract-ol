/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_set2(int check, t_fractol *fr)
{
	char	*it;

	if (fr->type != 4 && check == 1)
	{
		border(fr);
		text_window(fr);
	}
	fr->posy = 0;
	set_values(fr);
	it = ft_itoa(fr->iter);
	if (fr->type != 4 && check == 0)
		mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0xbdaabf, it);
	else if (check == 0)
	{
		border(fr);
		text_buddha(fr);
	}
	free(it);
	if (fr->type == 1)
	{
		mlx_string_put(fr->mlx, fr->win, fr->w + 130, 240, fr->c1, "<-");
		mlx_string_put(fr->mlx, fr->win, fr->t, 240, fr->c1, "mouse zoom");
		mlx_string_put(fr->mlx, fr->win, fr->t, 295, fr->c1, "mouse shape");
		mlx_string_put(fr->mlx, fr->win, fr->t, 320, fr->c1, "reset shape");
	}
}

void	change_set(char *argu, t_fractol *fr)
{
	char	*it;
	int		check;

	check = 0;
	if (fr->type == 4)
		check = 1;
	if (fr->type == 1)
	{
		mlx_string_put(fr->mlx, fr->win, fr->w + 130, 240, 0x000000, "<-");
		mlx_string_put(fr->mlx, fr->win, fr->w + 130, 295, 0x000000, "<-");
		mlx_string_put(fr->mlx, fr->win, fr->t, 240, 0x000000, "mouse zoom");
		mlx_string_put(fr->mlx, fr->win, fr->t, 295, 0x000000, "mouse shape");
		mlx_string_put(fr->mlx, fr->win, fr->t, 320, 0x000000, "reset shape");
	}
	it = ft_itoa(fr->iter);
	if (fr->type != 4)
		mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, 0x000000, it);
	free(it);
	fr->argu = argu;
	fr->type = type(fr);
	set_values(fr);
	change_set2(check, fr);
}

void	end(t_fractol *fr)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->win);
	free(fr->mlx);
	exit(0);
}

int		deal_key2(int key, t_fractol *fr)
{
	if (key == 122)
		zoom_in(fr);
	else if (key == 120)
		zoom_out(fr);
	else if (key == 114 || key == 99)
		reset(key, fr);
	else if (key == 119 || key == 115 || key == 97 || key == 100)
		move(key, fr);
	else if (fr->type == 1 && (key == 98 || key == 118))
		mouse(key, fr);
	else if (fr->type != 4 && (key == 65361 || key == 65363 || key == 103 ||
	key == 104 || key == 106 || key == 107) && fr->iter < 2000)
		iterate(key, fr);
	else if (key == 116)
	{
		if (fr->type == 4)
			text_buddha(fr);
		else
			text_window(fr);
	}
	mlx_destroy_image(fr->mlx, fr->img);
	draw(fr);
	return (0);
}

int		deal_key(int key, t_fractol *fr)
{
	if (key == 65307)
		end(fr);
	else if (key == 109 && fr->type != 4)
	{
		fr->multi++;
		if (fr->multi == 2)
			fr->multi = 0;
	}
	else if (key == 55)
		change_set("julia", fr);
	else if (key == 56)
		change_set("mandelbrot", fr);
	else if (key == 57)
		change_set("burningship", fr);
	else if (key == 48)
		change_set("buddhabrot", fr);
	else if (key >= 49 && key <= 54)
		style(key, fr);
	else
		return (deal_key2(key, fr));
	mlx_destroy_image(fr->mlx, fr->img);
	draw(fr);
	return (0);
}
