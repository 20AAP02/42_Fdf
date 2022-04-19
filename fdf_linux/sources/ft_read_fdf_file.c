#include <fdf.h>

int	ft_count_number_digs(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		if (*str == ' ')
			counter++;
		str++;
	}
	return (counter + 1);
}

int	**ft_read_fdf_file(char *file_name)
{
	int		**map;
	char	*str;
	int		fd;
	int		i;

	if (!file_name || *file_name == 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	map = malloc(sizeof(int *) * (ft_n_lines_file(file_name) + 2));
	map[ft_n_lines_file(file_name)] = NULL;
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		map[i] = malloc(sizeof(int) * ft_count_number_digs(str));
		ft_cpy_ln_to_intArr(map, str, i);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (map);
}