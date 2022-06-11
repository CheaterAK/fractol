/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:10 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 07:55:51 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

int	color(t_fract *fract, int r, int g, int b)
{
	int	o;

	o = 180;
	r *= fract->r;
	g *= fract->g;
	b *= fract->b;
	r *= 10;
	g *= 15;
	b *= 20;
	r %= 256;
	g %= 256;
	b %= 256;
	o *= fract->o;
	return (b | g << 8 | r << 16 | o << 24);
}

void	ft_color_init(t_fract *fract, int key)
{
	if (key == key_r)
		fract->r = (fract->r ^ 1);
	if (key == key_g)
		fract->g = (fract->g ^ 1);
	if (key == key_b)
		fract->b = (fract->b ^ 1);
	if (key == key_t)
		fract->o = (fract->o ^ 1);
}
