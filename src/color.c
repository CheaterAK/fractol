/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:10 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 11:26:07 by akocabas         ###   ########.fr       */
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
