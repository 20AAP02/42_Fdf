#include <fdf.h>

int	ft_count_number_digs(char *str)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while(str[i] == ' ')
				i++;
			counter++;
		}
		if (i > 0)
			if ((!str[i] && str[i-1] == ' ') || (str[i] == '\n' && str[i-1] == ' '))
				counter--;
		if (str[i])
			i++;
	}
	return (counter + 1);
}

t_map	*ft_read_fdf_file(char *file_name)
{
	t_map	*map_inf;
	int		file_lines;
	char	*str;
	int		fd;
	int		i;

	if (!file_name || *file_name == 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_inf = malloc(sizeof(t_map));
	file_lines = ft_n_lines_file(file_name) + 1;
	map_inf->map = malloc(sizeof(t_3dPt *) * (file_lines + 1));
	i = 0;
	str = get_next_line(fd);
	map_inf->width = ft_count_number_digs(str);
	while (str)
	{
		map_inf->map[i] = malloc(sizeof(t_3dPt) * map_inf->width);
		ft_cpy_ln_to_intArr(map_inf->map, str, i);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	map_inf->height = i;
	free(str);
	close(fd);
	return (map_inf);
}