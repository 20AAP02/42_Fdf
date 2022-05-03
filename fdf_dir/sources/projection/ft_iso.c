/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:28 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:19:39 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	iso(int x, int y, int z, int check)
{
	int	previous_x;
	int	previous_y;

	previous_x = x;
	previous_y = y;
	x = (previous_x - previous_y) * cos(0.523599);
	y = -z + ((previous_x + previous_y) * sin(0.523599));
	if (check)
		return (y);
	return (x);
}
