/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:57:32 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/25 07:27:24 by akocabas         ###   ########.fr       */
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
	burnungship = 2,
	julia = 3,
	tricorn = 4
};

enum {
	key_w = 13,
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
	scroll_up = 5,
	scroll_down = 3,
	key_plus = 69,
	key_minus = 78
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
	void		*prog;
	void		*parent_window;
	int			fract_type;
	double		angle;
}	t_fract;

int		ft_mandelbrot(t_fract *fract, int x, int y);
int		ft_burningship(t_fract *fract, int x, int y);
int		ft_tricorn(t_fract *fract, int x, int y);
int		mouse_hook(int key, t_fract *fract);
int		keydown(int key, t_fract *fract);
void	draw_fract(t_fract *fract);
void	ft_chk_px(t_fract *fract);

#endif
