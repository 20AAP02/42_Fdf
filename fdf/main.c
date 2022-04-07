#include <fdf.h>

// FOR MAC
// gcc -I 42_libft -I ft_printf -lmlx -framework OpenGL -framework AppKit main.c libft.a

// FOR OTHER MACS
// gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c
// int the place of "minilibx" could be "minilibx_macos_sierra"

// FOR LINUX (You may also need to specify the path to these libraries, using the -L flag)
// gcc -I 42_libft -I ft_printf -lmlx -lXext -lX11 main.c libft.a

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	t_img	img_bg;

	// initialize the connection between the program and the display
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

	// create a new window on the screen
	size_x = 1000;
	size_y = 1000;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Map Generator");

	// create image
	img_bg.width = size_x;
	img_bg.height = size_y;
	img_bg.img_ptr = mlx_new_image(mlx_ptr, img_bg.width, img_bg.height);

	// get info from image so that i can modify it
	img_bg.buffer = mlx_get_data_addr(img_bg.img_ptr, &img_bg.pixel_bits, &img_bg.line_bytes, &img_bg.endian);
	ft_fill_img(mlx_ptr, img_bg, 0x3a3d42);
	// put image in the screen
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_bg.img_ptr, 0, 0);

	mlx_loop(mlx_ptr);
	/*

	// destroys image
	mlx_destroy_image(mlx_ptr, img_ptr);

	mlx_string_put(mlx_ptr, win_ptr, 440, 500, 0xe8e7e6, "Hello world");

	// clears window (in black)
	mlx_clear_window(mlx_ptr, win_ptr);

	// destroys window
	mlx_destroy_window(mlx_ptr, win_ptr);
	*/

	return (0);
}

/*
How to draw pixels into the image?

The pixel data is initialized to 0, meaning every pixel will be black without alpha.

The pixel data is a single array of width * height * 4 bytes. For a 500x500 image, 
we would need 1’000’000 bytes or about 0.953 MB.

The way I like to iterate this array when pixel_bits == 32 is:

    y is the Y coordinate in the image.
        y == 0 is the first (top) pixel within the image.
        y * line_bytes lets us move up/down in pixel coordinates.
    
    x is the X coordinate in the image.
        x == 0 is the first (left) pixel.
        x lets us move left/right in pixel coordinates.
    
    Remember that one pixel on screen requires 4 bytes in memory.
    Remember that buffer is a char *.
       - When you increment the pointer by one by one, you’re moving forward one 
        byte in memory, so the final offset should be multiplied by 4.
    
    (y * line_bytes) + (x * 4) is the beginning of the data for that screen pixel.

From here, the “proper” way to draw the image according to the manual is to:

   - Check how many bits there are per pixel.
   - Convert your color with mlx_get_color_value if necessary.
   - Check whether the environment is little/big endian.
   - Write your color value byte-by-byte into the pixel array, according to 
    endianness.

*/