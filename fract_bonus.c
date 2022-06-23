/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:56:17 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/13 17:20:40 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"
 
void	my_put_pixel(t_data *data, int x, int y, int color)
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

	x = 0;
	y = 0;
	while (x < fract->img_size)
	{
		while (++y < fract->img_size)
		{
			if (fract->fract_type == julia)
				iter = ft_julia(fract, x, y, 1);
			else if (fract->fract_type == mandelbrot)
				iter = ft_mandelbrot(fract, x, y, 1);
			else if (fract->fract_type == burningship)
				iter = ft_burningship(fract, x, y, 1);
			else if (fract->fract_type == tricorn)
				iter = ft_tricorn(fract, x, y, 1);
			draw_fract(fract, x, y, iter);
		}
		y = -1;
		x++;
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window, fract->img.img,
		0, 0);
}
