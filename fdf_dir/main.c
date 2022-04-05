#include <math.h>
#include <libft.h>
#include <ft_printf.h>
#include <mlx.h>
#include <stdio.h> // printf

// FOR MAC
// gcc -I 42_libft -I ft_printf -lmlx -framework OpenGL -framework AppKit main.c libft.a

// FOR LINUX (You may also need to specify the path to these libraries, using the -L flag)
// gcc -I 42_libft -I ft_printf -lmlx -lXext -lX11 main.c libft.a

int ft_paint_background(void *mlx_ptr, void *win_ptr, int x, int y)
{
  int a;

  a = 0;
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
      a += mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x3a3d42);
  return (a);
}

int main(void)
{
  void *mlx_ptr;
  void *win_ptr;

  // initialize the connection between the program and the display
  mlx_ptr = mlx_init();
  if (!mlx_ptr)
    return (1);

  // create a new window on the screen
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Map Generator");
  
  ft_paint_background(mlx_ptr, win_ptr, 1000, 1000);
  
  mlx_loop(mlx_ptr);
  /*

  mlx_string_put(mlx_ptr, win_ptr, 440, 500, 0xe8e7e6, "Hello world");

  // clears window (in black)
  mlx_clear_window(mlx_ptr, win_ptr);

  // destroys window
  mlx_destroy_window(mlx_ptr, win_ptr);
  */

  return (0);
}