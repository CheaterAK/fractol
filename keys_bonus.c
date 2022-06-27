/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:29:26 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/27 17:27:24 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"
#include"minilibx_opengl_20191021/mlx.h"

void	ft_angle(t_fract *fract, int key)
{
	if (key == key_w)
		fract->julia_x += (.05 / fract->zoom);
	if (key == key_s)
		fract->julia_x -= (.05 / fract->zoom);
	if (key == key_a)
		fract->julia_y -= (.05 / fract->zoom);
	if (key == key_d)
		fract->julia_y += (.05 / fract->zoom);
}

void	ft_zoom(t_fract *fract, int key)
{
	if (key == key_minus)
	{
		fract->zoom = .8 * fract->zoom;
		fract->mv_y -= (.4 / fract->zoom);
		fract->mv_x -= (.4 / fract->zoom);
	}
	if (key == key_plus)
	{
		fract->zoom = 1.25 * fract->zoom;
		fract->mv_y += (.5 / fract->zoom);
		fract->mv_x += (.5 / fract->zoom);
		fract->max_iteration *= 1.01;
	}
}

void	ft_reinit(t_fract *fract, int key)
{
	if (key == key_1)
		fract_init("Burningship", fract);
	if (key == key_2)
		fract_init("Julia", fract);
	if (key == key_3)
		fract_init("Mandelbrot", fract);
	if (key == key_4)
		fract_init("Tricorn", fract);
}

int	keydown(int key, t_fract *fract)
{
	if (key == key_left)
		fract->mv_x -= (.1 / fract->zoom);
	if (key == key_right)
		fract->mv_x += (.1 / fract->zoom);
	if (key == key_up)
		fract->mv_y -= (.1 / fract->zoom);
	if (key == key_down)
		fract->mv_y += (.1 / fract->zoom);
	if (key == key_minus || key == key_plus)
		ft_zoom(fract, key);
	if (key == key_1 || key == key_2 || key == key_3 || key == key_4)
		ft_reinit(fract, key);
	if (key == key_n)
		fract->max_iteration++;
	if (key == key_esc)
		ft_destroy_it(fract);
	if (key == key_m)
		fract->max_iteration--;
	if (key == key_w || key == key_s || key == key_a || key == key_d)
		ft_angle(fract, key);
	if (key == key_r || key == key_g || key == key_b || key == key_t)
		ft_color_init(fract, key);
	ft_chk_px(fract);
	return (0);
}
