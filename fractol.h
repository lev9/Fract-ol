/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 12:10:59 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREADS 12
# define SIZE 720

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct	s_fractol
{
	void	*mlx;
	void	*win;
	char	*argu;
	void	*img;
	int		*buf;
	double	posx;
	double	posy;
	double	h;
	double	w;
	double	cx;
	double	cy;
	double	farx;
	double	fary;
	double	curx;
	double	cury;
	double	iter;
	double	zoom;
	int		pixel;
	int		type;
	int		style;
	double	twist;
	int		mouse;
	int		mousex;
	int		mousey;
	int		t;
	int		c1;
	int		c2;
	int		min;
	int		max;
	int		spots;
	int		value;
	double	randx;
	double	randy;
	int		screenx;
	int		screeny;
	int		c;
	int		multi;
	int		thread1;
	int		thread2;
	int		thread3;
	int		thread4;
	int		thread5;
	int		thread6;
	int		thread7;
	int		thread8;
	int		thread9;
	int		thread10;
	int		thread11;
	int		thread12;
}				t_fractol;

typedef struct	s_point
{
	double	farx;
	double	fary;
}				t_point;

typedef struct	s_const
{
	double	cx;
	double	cy;
}				t_const;

/*
**	main.c
*/
void			fr(char *argu);
int				main(int argc, char *argv[]);

/*
**	help.c
*/
int				directions(void);
int				errormessage(void);
int				unvalid(char *str);
int				type(t_fractol *fr);

/*
**	preparations.c
*/
void			border(t_fractol *fr);
void			text_buddha(t_fractol *fr);
void			text_window2(t_fractol *fr);
void			text_window(t_fractol *fr);

/*
**	draw_utils.c
*/
int				paint(t_fractol *fr, int i, t_point point, int pixel);
void			draw(t_fractol *fr);
void			set_values2(t_fractol *fr);
void			set_values(t_fractol *fr);
void			image_values(t_fractol *fr);

/*
**	threader.c
*/
void			one(t_fractol *fr);
void			two(t_fractol *fr);
void			three(t_fractol *fr);
void			four(t_fractol *fr);
void			five(t_fractol *fr);

/*
**      threader2.c
*/
void			six(t_fractol *fr);
void			seven(t_fractol *fr);
void			eight(t_fractol *fr);
void			nine(t_fractol *fr);
void			ten(t_fractol *fr);

/*
**	threader3.c
*/
void			eleven(t_fractol *fr);
void			twelve(t_fractol *fr);
int				get_z(t_fractol *fr);
int				create_threads(pthread_t *threads, t_fractol *fr);
int				join_threads(pthread_t *threads);

/*
**	fractols.c
*/
void			iterjulia(t_fractol *fr, double x, double y, int pixel);
void			julia(t_fractol *fr);
void			itermandel(t_fractol *fr, int pixel, t_const c);
void			mandel(t_fractol *fr);
void			draw_set(t_fractol *fr);

/*
**	buddhabrot.c
*/
void			antibud(t_fractol *fr);
void			apply(t_fractol *fr, int i, int min);
void			handle_spot(t_fractol *fr, int min, int max);
void			addcolor(t_fractol *fr);
void			buddhabrot(t_fractol *fr);

/*
**      buddhavalues.c
*/
void			minim(t_fractol *fr);
void			maxim(t_fractol *fr);
void			get_spots(t_fractol *fr);
void			get_zoom(int style, t_fractol *fr);
void			get_random(int count, t_fractol *fr);

/*
**	styles.c
*/
int				energystyle(t_fractol *fr, int i, t_point point, int pixel);
int				shipenergy(t_fractol *fr, int i, t_point point, int pixel);
int				light(t_fractol *fr, int i, t_point point, int pixel);
int				metal(t_fractol *fr, int i, t_point point, int pixel);

/*
**	styles2.c
*/
int				candy(t_fractol *fr, int i, t_point point, int pixel);
int				rb(t_fractol *fr, int i, t_point point, int pixel);
int				bluey(t_fractol *fr, int i, t_point point, int pixel);
void			get_iter(t_fractol*fr);
int				get_multi(t_fractol *fr);

/*
**	colors.c
*/
int				beach_color(double n);
int				get_gray(double n);
int				energy(double n);
int				rainbow(double n);
int				basic(t_fractol *fr, int i);

/*
**      colors2.c
*/
int				unicorny(double n);
int				unicorny2(double n, int r, int g, int b);
int				unicorny3(double n, int r, int g, int b);

/*
**	zoom.c
*/
void			zoom_in(t_fractol *fr);
void			zoom_out(t_fractol *fr);
int				zoomer(int button, int x, int y, t_fractol *fr);

/*
**      mouse.c
*/
void			press2(int x, int y, t_fractol *fr);
int				press(int x, int y, t_fractol *fr);
int				deal_mouse(int button, int x, int y, t_fractol *fr);
int				julia_constant(int x, int y, t_fractol *fr);
int				deal_mouse2(int x, int y, t_fractol *fr);

/*
**	highlight.c
*/
int				highlihtbuddha(int x, int y, t_fractol *fr);
int				highlightsettings(int x, int y, t_fractol *fr);
int				highlightiter(int x, int y, t_fractol *fr);
int				highlighnames(int x, int y, t_fractol *fr);
int				highlighter(int x, int y, t_fractol *fr);

/*
**	keys.c
*/
void			change_set(char *argu, t_fractol *fr);
void			end(t_fractol *fr);
int				deal_key2(int key, t_fractol *fr);
int				deal_key(int key, t_fractol *fr);

/*
**	keys2.c
*/
void			style(int key, t_fractol *fr);
void			mouse(int key, t_fractol *fr);
void			reset(int key, t_fractol *fr);
void			iterate(int key, t_fractol *fr);
void			move(int key, t_fractol *fr);

#endif
