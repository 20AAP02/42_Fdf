/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_ln_to_intArr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:18 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 17:19:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_cpy_ln_to_intarr(t_3dPt **map, char *str, int i)
{
	int		a;
	int		b;
	int		map_index;
	char	*str_n;

	a = 0;
	map_index = 0;
	while (str[a])
	{
		b = a;
		while (str[b] && str[b] != ' ' && str[b] != '\n')
			b++;
		if (b - a > 0)
		{
			str_n = ft_substr(str, a, b - a);
			map[i][map_index].altitude = ft_atoi(str_n);
			map[i][map_index].alt2 = map[i][map_index].altitude;
			if (ft_memchr(str_n, ',', ft_strlen(str_n)))
				map[i][map_index].color = ft_hexstr_toint(ft_memchr(str_n, ',', ft_strlen(str_n)) + 1);
			else
				map[i][map_index].color = 0xffffff;
			free(str_n);
			map_index++;
		}
		if (!str[b])
			a = b;
		else
			a = b + 1;
	}
}
