/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:54:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 16:54:55 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_map_width(char *str)
{
	int	i;
	int	counter;
	int	space;

	counter = 0;
	space = 1;
	i = 0;
	while (str[i])
	{
		if (space && ft_isdigit(str[i]))
		{
			counter++;
			space = 0;
		}
		if (str[i] == ' ')
			space = 1;
		i++;
	}
	return (counter);
}
