/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:28 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 04:12:49 by akocabas         ###   ########.fr       */
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
