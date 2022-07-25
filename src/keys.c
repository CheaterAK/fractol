/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:29:26 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/25 11:40:40 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"
#include "./mlx.h"

void	ft_juli(t_fract *fract, int key)
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
	if (key == key_minus || key == scroll_down)
	{
		fract->zoom = .8 * fract->zoom;
		fract->mv_y -= (.4 / fract->zoom);
		fract->mv_x -= (.4 / fract->zoom);
	}
	if (key == key_plus || key == scroll_up)
	{
		fract->zoom = 1.25 * fract->zoom;
		fract->mv_y += (.5 / fract->zoom);
		fract->mv_x += (.5 / fract->zoom);
		fract->max_iteration *= 1.01;
	}
}

int	ft_keydown(int key, t_fract *fract)
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
	if (key == key_esc)
		ft_destroy_it(fract);
	if (key == key_w || key == key_s || key == key_a || key == key_d)
		ft_juli(fract, key);
	ft_chk_px(fract);
	return (0);
}

int	ft_m_move(int x, int y, t_fract *fract)
{
	if ((x >= fract->img_size || x < 0) || y >= fract->img_size || y < 0)
	{
		return (0);
	}
	if (!fract->key_flag)
		return (0);
	fract->julia_x = (-1 + (double)x / (fract->img_size / 2)) / fract->zoom;
	fract->julia_y = (-1 + (double)y / (fract->img_size / 2)) / fract->zoom;
	ft_chk_px(fract);
	return (1);
}

int	ft_mouse_hook(int key, int x, int y, t_fract *fract)
{
	if (key == scroll_down || key == scroll_up)
	{
		ft_zoom(fract, key);
	}
	if (key == right_click)
		fract->key_flag = fract->key_flag ^ 1;
	x = 0;
	y = 0;
	ft_chk_px(fract);
	return (0);
}
