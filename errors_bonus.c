/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:28 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 06:40:41 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"

void	ft_error_message(void)
{
	printf("Usage: ./fractol [fratals] [preset for julia]\nPreset is an optiona\
l paramater.\n\"./fractol help\" for show keys.\n WARNING: \nIf you don't use a\
 preset, the imaginary number and the real number are treated as 0.\n fratals :\
\n---> Mandelbrot\n---> Julia\n---> Burningship\n---> Tricorn\n presets:\n---> \
1 = 0, 0.8i\n---> 2 = -0.4, -0.6i\n---> 3 = -0.70176, -0.3842i\n---> 4 = 0.285,\
 0.01i\nExample Code : ./fractol Julia 2\n");
}

void	ft_invalid_julia(void)
{
	printf("Invalid julia preset\nTry valid one following like in the guide.\n");
	ft_error_message();
	exit(1);
}

void	ft_invalid_fract(void)
{
	printf("Invalid fractol\nTry valid one following like in the guide.\n");
	ft_error_message();
	exit(1);
}

void	ft_help(void)
{
	printf("Key 1 = Set to main fractol Burningship.\nKey 2 = Set to main fract\
ol Julia.\nKey 3 = Set to main fractol Mandelbrot.\nKey 4 = Set to main fractol\
 Tricorn.\nKey w = Increases Julia's imaginer number by 0.05.\nKey s = Decrease\
 Julia's imaginer number by 0.05.\nKey d = Increase Julia's real number by 0.05\
.\nKey a = DecreaseJulia's real number by 0.05.\nKey r = Add\\remove red color.\
\nKey g = Add\\remove green color.\nKey b = Add\\remove blue color.\nKey t = Ad\
d\\remove transparancy.\nKey n = Increase max iteration.\nKey m = Decrease max \
iteration.\nKey up = Move up.\nKey down = Move down.\nKey left = Move left.\nke\
y right = Move right.\nKey esc = Exit prog.\nKey numpad plus = Zoom in.\nKey nu\
mped minus = Zoom out.\nMouse 1 = color shift.\nMouse 2 = Special Key for julia\
.\nMouse wheel = zoom in\\zoom out on position of mouse.\n");
	exit(0);
}
