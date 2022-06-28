/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:28 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 04:41:44 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"

void	ft_error_message(void)
{
	printf("Usage: ./fractol [fratals] [preset for julia]\nPreset is an optiona\
l paramater.\n WARNING: \nIf you don't use a preset, the imaginary number and t\
he real number are treated as 0.\n fratals :\n---> Mandelbrot\n---> Julia\n pre\
sets:\n---> 1 = 0, -0.8i\n---> 2 = -0.4, 0.6i\n---> 3 = -0.70176, -0.3842i\n---\
> 4 = 0.285, 0.01i\nExample Code : ./fractol Julia 2\n");
	exit(1);
}

void	ft_invalid_julia(void)
{
	printf("Invalid julia preset\nTry valid one following like in the guide.\n");
	ft_error_message();
}

void	ft_invalid_fract(void)
{
	printf("Invalid fractol\nTry valid one following like in the guide.\n");
	ft_error_message();
}

void	ft_help(void)
{
	printf("key_1 = Set to main fractol Burningship.\nkey_2 = Set to main fract\
ol Julia.\nkey_3 = Set to main fractol Mandelbrot.\nkey_4 = Set to main fractol\
 Tricorn.\nkey_w = Increase 0.05 to Julia's imaginer number on C.\nkey_s = Decr\
ease 0.05 Julia's imaginer number on C.\nkey_d = Increase 0.05 to Julia's imagi\
ner number on C.\nkey_a = Decrease 0.05 Julia's real number on C.\nkey_r = Add\\
\remove red color.\nkey_g = Add\\remove green color.\nkey_b = Add\\remove blue \
color.\nkey_t = Add\\remove transparancy.\nkey_n = Increase max iteration.\nkey\
_m = Decrease max iteration.\nkey_up = Move up.\nkey_down = Move down.\nkey_lef\
t = Move left.\nkey_right = Move right.\nkey_esc = Exit prog.\nkey_plus = Zoom \
in.\nkey_minus = Zoom out.\n")
}
