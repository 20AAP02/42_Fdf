#include <fdf.h>

int main(void)
{
  void  *mlx;
  void  *window;
  void  *img;
  char  *buffer;
  int   pixel_bits;
  int   line_bytes;
  int   endian;
  int   pixel;

  
  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 1000, "Title");
  img = mlx_new_image(mlx, 1000, 1000);
  buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
  pixel = (10 * line_bytes) + (10 * 4);
  ft_color_img_pixel(buffer, endian, pixel, 0xFFFFFF);
  pixel = (20 * line_bytes) + (20 * 4);
  ft_color_img_pixel(buffer, endian, pixel, 0xFFFF);
  mlx_put_image_to_window(mlx, window, img, 0, 0);
  mlx_loop(mlx);
  return (0);
}