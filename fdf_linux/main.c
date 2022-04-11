#include <fdf.h>

int	main(void)
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_ln	line;


	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Map Generator");
	img.height = 1000;
	img.width = 1000;
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	img.buffer = mlx_get_data_addr(img.img_ptr, &img.pixel_bits, &img.line_bytes, &img.endian);
	ft_fill_img(mlx, &img, 0x3a3d42);
	ft_draw_diamond(mlx, &img, 0xFFFF);
	line = ft_init_line(500, 0, 500, 999);
	ft_draw_line(mlx, &img, line, 0xFFFFFF);
	mlx_put_image_to_window(mlx, window, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}