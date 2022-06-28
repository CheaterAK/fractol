/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:10 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 04:04:11 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"

int	color(t_fract *fract, int r, int g, int b)
{
	int	o;

	o = 0;
	r *= 10;
	g *= 15;
	b *= 20;
	r %= 256;
	g %= 256;
	b %= 256;
	return (b | g << 8 | r << 16 | o << 24);
}
