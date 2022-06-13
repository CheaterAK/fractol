/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:29:26 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 11:26:12 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

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
	if (key == key_esc)
		ft_destroy_it(fract);
	if (key == key_w || key == key_s || key == key_a || key == key_d)
		ft_angle(fract, key);
	ft_chk_px(fract);
	return (0);
}
