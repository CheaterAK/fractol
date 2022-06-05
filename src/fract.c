/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:56:17 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/03 19:21:28 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

int	color(int o, int r, int g, int b)
{
	r = (r * 10) % 256;
	g = (g * 20) % 256;
	if (r < 50)
		r = 50;
	b = (b * 30) % 256;
	return (o << 24 | r << 16 | g << 8 | b);
}

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

	x = 0;
	y = 0;
	while (x < 600)
	{
		while (y < 600)
		{
			draw_fract(fract, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window, fract->img.img,
		0, 0);
}
