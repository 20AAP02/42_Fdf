#include <fdf.h>

int	ft_n_lines_file(char *file_name)
{
	int fd;
    int n;
    int count;
    char str[1];

    fd = open(file_name, O_RDONLY);
	count = 0;
	n = read(fd, str, sizeof(char));
	while (n != 0)
	{
		if (*str == '\n')
			count++;
		n = read(fd, str, sizeof(char));
	}
    return (count);
}