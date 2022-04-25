#include <fdf.h>

int	ft_getRed(int i)
{
	return ((i >> 16) & 0xFF);
}

int	ft_getGreen(int	i)
{
	return ((i >> 8) & 0xFF);
}

int	ft_getBlue(int	i)
{
	return (i & 0xFF);
}
