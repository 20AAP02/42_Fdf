/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:54:33 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:36 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_free_map(t_map *map_inf)
{
	int	i;

	i = 0;
	if (map_inf)
		if (map_inf->map)
			while (i < map_inf->height)
				free(map_inf->map[i++]);
	if (map_inf)
		if (map_inf->map)
			free(map_inf->map);
	if (map_inf)
		free(map_inf);
}
