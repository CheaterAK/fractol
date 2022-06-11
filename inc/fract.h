/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:57:32 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 08:12:01 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

enum {
	mandelbrot = 1,
	burningship = 2,
	julia = 3,
	tricorn = 4
};

enum {
	key_1 = 18,
	key_2 = 19,
	key_3 = 20,
	key_4 = 21,
	key_w = 13,
	key_r = 15,
	key_g = 5,
	key_b = 11,
	key_t = 17,
	key_a = 0,
	key_s = 1,
	key_d = 2,
	key_n = 45,
	key_m = 46,
	key_up = 126,
	key_down = 125,
	key_left = 123,
	key_right = 124,
	key_esc = 53,
	key_plus = 69,
	key_minus = 78
};
enum {
	left_click = 1,
	right_click = 2,
	middle_click = 3,
	scroll_up = 5,
	scroll_down = 4
};

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_fract
{
	t_complex	c;
	t_complex	z;
	int			max_iteration;
	double		mv_x;
	double		mv_y;
	double		zoom;
	t_data		img;
	t_data		mini_fract1;
	t_data		mini_fract2;
	t_data		mini_fract3;
	void		*prog;
	void		*parent_window;
	int			fract_type;
	int			mini_fract1_type;
	int			mini_fract2_type;
	int			mini_fract3_type;
	double		angle;
	int			color_shift;
	int			r;
	int			g;
	int			b;
	int			o;
	int			img_size;
	int			mini_fract_size;
	double		julia_x;
	double		julia_y;
	int			key_flag;
}	t_fract;

int		ft_julia(t_fract *fract, int x, int y, int scale);
int		ft_mandelbrot(t_fract *fract, int x, int y, int scale);
int		ft_burningship(t_fract *fract, int x, int y, int scale);
int		ft_tricorn(t_fract *fract, int x, int y, int scale);
int		mouse_hook(int key, int x, int y, t_fract *fract);
int		keydown(int key, t_fract *fract);
void	draw_fract(t_fract *fract, int x, int y, int iter);
void	ft_chk_px(t_fract *fract);
int		ft_destroy_it(t_fract *fract);
void	my_put_pixel(t_data *data, int x, int y, int color);
int		color(t_fract *fract, int r, int g, int b);
void	ft_chk_px(t_fract *fract);
void	ft_color_init(t_fract *fract, int key);
void	draw_mfract1(t_fract *fract, int x, int y);
void	draw_mfract2(t_fract *fract, int x, int y);
void	draw_mfract3(t_fract *fract, int x, int y);
void	mfract_checkpx(t_fract *fract);
void	fract_init(char *fract_name, t_fract *fract);

#endif
