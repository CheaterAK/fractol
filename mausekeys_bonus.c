/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mausekeys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:08:00 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/13 14:10:15 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"
#include "./minilibx_macos/mlx.h"

void	ft_mzoom(t_fract *fract, int key, int y, int x)
{
	if (key == scroll_down)
	{
		fract->zoom = .8 * fract->zoom;
		fract->mv_y -= (((double)y / 800) / fract->zoom);
		fract->mv_x -= (((double)x / 800) / fract->zoom);
	}
	if (key == scroll_up)
	{
		fract->zoom = 1.25 * fract->zoom;
		fract->mv_y += (((double)y / 600) / fract->zoom);
		fract->mv_x += (((double)x / 600) / fract->zoom);
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
	fract->julia_x = (-1 + (double)x / 300) / fract->zoom;
	fract->julia_y = (-1 + (double)y / 300) / fract->zoom;
	ft_chk_px(fract);
	return (1);
}

int	mouse_hook(int key, int x, int y, t_fract *fract)
{
	if (key == scroll_down || key == scroll_up)
	{
		ft_mzoom(fract, key, y, x);
	}
	if (key == left_click)
		if (fract->color_shift++ == 2)
			fract->color_shift = 0;
	if (key == right_click)
	{
		if (fract->key_flag)
			fract->key_flag = 0;
		else
			fract->key_flag = 1;
	}
	ft_chk_px(fract);
	return (0);
}
