/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getRGB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:26:48 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 15:40:11 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

float	ft_get_red(int i)
{
	return ((float)((i >> 16) & 0xFF));
}

float	ft_get_green(int i)
{
	return ((float)((i >> 8) & 0xFF));
}

float	ft_get_blue(int i)
{
	return ((float)(i & 0xFF));
}
