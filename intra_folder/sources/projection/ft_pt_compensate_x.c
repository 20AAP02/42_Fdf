/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_compensate_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:21:24 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_pt_compensate_x(t_map *map_inf)
{
	int	comp;

	comp = 0;
	while (ft_lowest_x(map_inf, comp) < 0)
		comp++;
	return (comp);
}
