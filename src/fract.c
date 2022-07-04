/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:56:17 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/04 04:58:12 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"
#include "./mlx.h"

void	ft_my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_chk_px(t_fract *fract)
{
	int	x;
	int	y;
	int	iter;

	x = -1;
	y = -1;
	while (++x < fract->img_size)
	{
		while (++y < fract->img_size)
		{
			if (fract->fract_type == julia)
				iter = ft_julia(fract, x, y, 1);
			else if (fract->fract_type == mandelbrot)
				iter = ft_mandelbrot(fract, x, y, 1);
			ft_draw_fract(fract, x, y, iter);
		}
		y = -1;
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window, fract->img.img,
		0, 0);
}
