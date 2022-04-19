#include <fdf.h>

int	**ft_read_fdf_file(char *file_name)
{
	int	**map;
	char	*str;
	int	fd;

	if (!file_name || *file_name != 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	map = NULL;
	return (map);
}