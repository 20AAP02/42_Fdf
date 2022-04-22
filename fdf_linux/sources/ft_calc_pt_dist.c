#include <fdf.h>

int	ft_calculate_pt_dist(int map_width, int img_width, int map_height, int img_height)
{
	int pt_dist;

	pt_dist = img_width;
	while ((map_width * pt_dist) >= img_width)
		pt_dist--;
	while ((map_height * pt_dist) >= img_height)
		pt_dist--;
	return (pt_dist);
}