/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:28 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/04 04:41:01 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "../ft_printf/ft_printf.h"

void	ft_error_message(void)
{
	ft_printf("Usage: ./fractol [fratals] [preset for julia]\nPreset is an optiona\
l paramater.\n\"./fractol help\" for show keys.\n WARNING: \nIf you don't use a\
 preset, the imaginary number and the real number are treated as 0.\n fratals :\
 \n---> Mandelbrot\n---> Julia\n presets:\n---> 1 = 0, -0.8i\n---> 2 = -0.4, 0.\
6i\n---> 3 = -0.70176, -0.3842i\n---> 4 = 0.285, 0.01i\nExample Code : ./fracto\
l Julia 2\n");
	exit(1);
}

void	ft_invalid_julia(void)
{
	ft_printf("Invalid julia preset\nTry valid one following like in the guide\
.\n");
	ft_error_message();
}

void	ft_invalid_fract(void)
{
	ft_printf("Invalid fractol\nTry valid one following like in the guide.\n");
	ft_error_message();
}

void	ft_help(void)
{
	ft_printf("Key w = Increases Julia's imaginer number by 0.05.\nKey s = Decr\
ease Julia's imaginer number by 0.05.\nKey d = Increase Julia's real number by \
0.05\nKey a = DecreaseJulia's real number by 0.05.\nKey up = Move up.\nKey down\
 = Move down.\nKey left = Move left.\nkey right = Move right.\nKey esc = Exit p\
rog.\nKey numpad plus = Zoom in.\nKey numped minus = Zoom out.\nMouse 2 = Speci\
al Key for julia.\nMouse wheel = zoom in\\zoom out.\n");
	exit(0);
}
