/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:29:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 15:43:12 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	get_light(float start, float end, float percent)
{
	return ((1.0 - (percent / 100.0)) * start + (percent / 100.0) * end);
}

int	ft_linear_gradient(int colors[2], int percent)
{
	int	red;
	int	green;
	int	blue;
	int	num;

	if (colors[0] == colors[1])
		return (colors[0]);
	num = ft_get_red(colors[1]);
	red = get_light(ft_get_red(colors[0]), num, (float)percent);
	num = ft_get_green(colors[1]);
	green = get_light(ft_get_green(colors[0]), num, (float)percent);
	num = ft_get_blue(colors[1]);
	blue = get_light(ft_get_blue(colors[0]), num, (float)percent);
	return ((red << 16) | (green << 8) | blue);
}
