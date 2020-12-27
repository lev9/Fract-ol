/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		directions(void)
{
	write(1, "==================================================\n", 51);
	write(1, "KEY CONTROL:\n", 14);
	write(1, "zoom in/out: z/x\n", 17);
	write(1, "move: a/w/d/s\n", 14);
	write(1, "iteration:\n", 11);
	write(1, "-10: g  +10: h  -100: j  +100: k  -1/+1: arrows\n", 48);
	write(1, "choose set: 7 - 0\n", 18);
	write(1, "choose style: 1 - 6\n", 20);
	write(1, "reset zoom: r\n", 14);
	write(1, "reset julia shape: c\n", 21);
	write(1, "julia/  switch to zoom: v  switch to shaping: b\n", 48);
	write(1, "quit: esc\n", 10);
	write(1, "==================================================\n", 51);
	return (0);
}

int		errormessage(void)
{
	ft_putstr_fd("\nvalid parameters are (choose one please):\n", 1);
	ft_putstr_fd("\njulia\nmandelbrot\nburningship\nbuddhabrot\n\n", 1);
	return (-1);
}

int		unvalid(char *str)
{
	if (ft_strcmp(str, "julia") == 0 || ft_strcmp(str, "mandelbrot") == 0
	|| ft_strcmp(str, "burningship") == 0 || ft_strcmp(str, "buddhabrot") == 0)
		return (0);
	return (1);
}

int		type(t_fractol *fr)
{
	if (ft_strcmp(fr->argu, "julia") == 0)
		return (1);
	if (ft_strcmp(fr->argu, "mandelbrot") == 0)
		return (2);
	if (ft_strcmp(fr->argu, "burningship") == 0)
		return (3);
	if (ft_strcmp(fr->argu, "buddhabrot") == 0)
		return (4);
	if (ft_strcmp(fr->argu, "ball") == 0)
		return (5);
	return (0);
}
