/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mixer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:26:23 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 15:26:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_color_mixer(int range[2], int altitude, t_map *map_inf)
{
	int	percent;
	int	dist;
	int	color[2];

	color[0] = map_inf->colors[0];
	color[1] = map_inf->colors[1];
	if (altitude == range[0])
		return (color[0]);
	if (altitude == range[1])
		return (color[1]);
	dist = abs(altitude - range[0]);
	percent = (dist * 100) / (range[1] - range[0]);
	return (ft_linear_gradient(color, percent));
}
