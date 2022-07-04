/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:10 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/03 21:29:03 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"

int	ft_color(t_fract *fract, int iter)
{
	int	o;
	int	r;
	int	g;
	int	b;

	o = 180;
	r = iter;
	g = iter;
	b = iter;
	r *= fract->r * 10;
	g *= fract->g * 15;
	b *= fract->b * 20;
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
	if (key == key_tra)
		fract->o = (fract->o ^ 1);
}
