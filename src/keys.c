/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:29:26 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/25 08:13:52 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

void	ft_angle_zoom(t_fract *fract, int key)
{
	if (key == key_up)
	{
		fract->zoom = 1.2 * fract->zoom;
		fract->mv_y += (.4 / fract->zoom);
		fract->mv_x += (fract->angle * .4 / fract->zoom);
		fract->max_iteration *= 1.01;
	}
	if (key == key_down)
	{
		fract->zoom = .833333 * fract->zoom;
		fract->mv_y -= (.34 / fract->zoom);
		fract->mv_x -= (fract->angle * .34 / fract->zoom);
	}
	if (key == key_left)
		fract->angle += .03;
	if (key == key_right)
		fract->angle -= .03;
}

void	ft_zoom(t_fract *fract, int key)
{
	if (key == key_minus)
	{
		fract->zoom = .833333 * fract->zoom;
		fract->mv_y -= (.34 / fract->zoom);
		fract->mv_x -= (.34 / fract->zoom);
	}
	if (key == key_plus)
	{
		fract->zoom = 1.2 * fract->zoom;
		fract->mv_y += (.4 / fract->zoom);
		fract->mv_x += (.4 / fract->zoom);
		fract->max_iteration *= 1.01;
	}
}

int	keydown(int key, t_fract *fract)
{
	if (key == key_a)
		fract->mv_x += (.1 / fract->zoom);
	if (key == key_d)
		fract->mv_x -= (.1 / fract->zoom);
	if (key == key_w)
		fract->mv_y += (.1 / fract->zoom);
	if (key == key_s)
		fract->mv_y -= (.1 / fract->zoom);
	if (key == key_minus || key == key_plus)
		ft_zoom(fract, key);
	if (key == key_n)
		fract->max_iteration++;
	if (key == key_m)
		fract->max_iteration--;
	if (key == key_up || key == key_down || key == key_left || key == key_right)
		ft_angle_zoom(fract, key);
	ft_chk_px(fract);
	return (0);
}

int	mouse_hook(int key, t_fract *fract)
{
	if (key == scroll_down)
		fract->zoom = 1.2 * fract->zoom;
	if (key == scroll_up)
		fract->zoom = .8 * fract->zoom;
	ft_chk_px(fract);
	return (0);
}
