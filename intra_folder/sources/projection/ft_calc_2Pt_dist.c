/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_2Pt_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:12 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:18:19 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_calc_2pt_dist(t_pt pt1, t_pt pt2)
{
	int	dx;
	int	dy;

	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	dx = ft_recursive_power(dx, 2);
	dy = ft_recursive_power(dy, 2);
	dx = sqrt(dx + dy);
	return (dx);
}
