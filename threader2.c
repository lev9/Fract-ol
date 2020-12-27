/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	six(t_fractol *fr)
{
	fr->thread6 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	seven(t_fractol *fr)
{
	fr->thread7 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	eight(t_fractol *fr)
{
	fr->thread8 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	nine(t_fractol *fr)
{
	fr->thread9 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	ten(t_fractol *fr)
{
	fr->thread10 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}
