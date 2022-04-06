#include <math.h>
#include <libft.h>
#include <ft_printf.h>
#include <mlx.h>
#include <stdio.h> // printf

// FOR MAC
// gcc -I 42_libft -I ft_printf -lmlx -framework OpenGL -framework AppKit main.c libft.a

// FOR LINUX (You may also need to specify the path to these libraries, using the -L flag)
// gcc -I 42_libft -I ft_printf -lmlx -lXext -lX11 main.c libft.a

typedef struct t_img
{
  void  *img_ptr;
  int   pixel_bits;
  int   line_bytes;
  int   endian;
  char  *buffer;
  int width;
  int height;
}       t_img;

void ft_color_img_pixel(t_img img, int pixel, int color)
{
  if (img.endian)
  {
    img.buffer[pixel + 0] = (color >> 24);
    img.buffer[pixel + 1] = (color >> 16) & 0xFF;
    img.buffer[pixel + 2] = (color >> 8) & 0xFF;
    img.buffer[pixel + 3] = (color) & 0xFF;
  }
  else
  {
    img.buffer[pixel + 0] = (color) & 0xFF;
    img.buffer[pixel + 1] = (color >> 8) & 0xFF;
    img.buffer[pixel + 2] = (color >> 16) & 0xFF;
    img.buffer[pixel + 3] = (color >> 24);
  }
}
char a = 'o';
int arr[127];
arr[a] = 1;

void ft_fill_img(void *mlx_ptr, t_img img, int color)
{
  int pixel;

  if (img.pixel_bits != 32)
    color = mlx_get_color_value(mlx_ptr, color);
  
  for (int y = 0; y < img.height; y++)
  {
    for (int x = 0; x < img.width; x++)
    {
      pixel = (y * img.line_bytes) + (x * 4);
      ft_color_img_pixel(img, pixel, color);
    }
    
  }
  
}

int main(void)
{
  void *mlx_ptr;
  void *win_ptr;
  t_img img_bg;

  // initialize the connection between the program and the display
  mlx_ptr = mlx_init();
  if (!mlx_ptr)
    return (1);

  // create a new window on the screen
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Map Generator");

  // create image
  img_bg.width = 1000;
  img_bg.height = 1000;
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