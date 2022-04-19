#include <fdf.h>

int	main(int argc, char **argv)
{
	int		**map;
	void	*mlx;
	void	*win;
	t_img	img;

	// read map.fdf file
	if ((argc != 2) || (ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 5) == NULL))
		return (0);
	map = ft_read_fdf_file(argv[1]);
	if (!map)
		return (0);
	ft_free_map(map);
	// Create window and such
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Map Generator");
	img.height = 1000;
	img.width = 1000;
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	img.buffer = mlx_get_data_addr(img.img_ptr, &img.pixel_bits, &img.line_bytes, &img.endian);
	ft_fill_img(mlx, &img, 0x3a3d42);
	mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
	ft_setup_hooks(&img, mlx, win);
	mlx_loop(mlx);
	return (0);
}