/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_ln_to_intArr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:18 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/02 18:15:21 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

typedef struct s_v
{
	int		a;
	int		b;
	int		map_index;
	char	*str_n;
	char	*mem;
}			t_v;

char	*ft_cpy_ln_to_intarr(t_3dPt **map, char *str, int i)
{
	t_v	x;

	x.a = 0;
	x.map_index = 0;
	while (str[x.a])
	{
		x.b = x.a;
		while (str[x.b] && str[x.b] != ' ' && str[x.b] != '\n')
			x.b++;
		if (x.b - x.a > 0)
		{
			x.str_n = ft_substr(str, x.a, x.b - x.a);
			map[i][x.map_index].altitude = ft_atoi(x.str_n);
			map[i][x.map_index].alt2 = map[i][x.map_index].altitude;
			x.mem = ft_memchr(x.str_n, ',', ft_strlen(x.str_n));
			if (x.mem)
				map[i][x.map_index].color = ft_hexstr_toint(x.mem + 1);
			else
				map[i][x.map_index].color = 0xffffff;
			free(x.str_n);
			x.map_index++;
		}
		x.a = x.b + (str[x.b] != '\0');
	}
	return (str);
}
