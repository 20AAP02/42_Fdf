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