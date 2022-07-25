/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousekeys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:08:00 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/06 08:30:44 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_bonus.h"
#include "mlx.h"

void	ft_mzoom(t_fract *fract, int key, int y, int x)
{
	if (key == scroll_down)
	{
		fract->zoom = .8 * fract->zoom;
		fract->mv_y -= (((double)y / fract->img_size * .8) / fract->zoom);
		fract->mv_x -= (((double)x / fract->img_size * .8) / fract->zoom);
	}
	if (key == scroll_up)
	{
		fract->zoom = 1.25 * fract->zoom;
		fract->mv_y += ((double)y / fract->img_size / fract->zoom);
		fract->mv_x += ((double)x / fract->img_size / fract->zoom);
		fract->max_iteration *= 1.01;
	}
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
	return (0);
}

int	ft_mouse_hook(int key, int x, int y, t_fract *fract)
{
	if (key == scroll_down || key == scroll_up)
	{
		ft_mzoom(fract, key, y, x);
	}
	if (key == left_click)
		if (fract->color_shift++ == 2)
			fract->color_shift = 0;
	if (key == right_click)
		fract->key_flag ^= 1;
	ft_chk_px(fract);
	return (0);
}
