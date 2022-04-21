#include <fdf.h>

void	ft_cpy_ln_to_intArr(int **map, char *str, int i)
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
			map[i][map_index] = ft_atoi(str_n);
			free(str_n);
			map_index++;
		}
		a = b + 1;
	}
}