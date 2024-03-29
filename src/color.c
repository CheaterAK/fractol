/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:10 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/06 06:55:39 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_color(int r, int g, int b)
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
