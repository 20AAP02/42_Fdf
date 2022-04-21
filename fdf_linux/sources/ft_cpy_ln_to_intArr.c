#include <fdf.h>

void	ft_cpy_ln_to_intArr(t_3dPt **map, char *str, int i)
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
			str_n = ft_substr(str, a, b);
			map[i][map_index].altitude = ft_atoi(str_n);
			if (ft_memchr(str_n, ',', ft_strlen(str_n)))
				map[i][map_index].color = ft_hexStr_toInt(ft_memchr(str_n, 'x', ft_strlen(str_n)));
			else
				map[i][map_index].color = 0x0;
			free(str_n);
			map_index++;
		}
		a = b + 1;
	}
}
