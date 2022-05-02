/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:54:44 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:45 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_ln	ft_init_line(int x0, int y0, int x1, int y1)
{
	t_ln	line;

	line.a.x = x0;
	line.a.y = y0;
	line.b.x = x1;
	line.b.y = y1;
	return (line);
}
