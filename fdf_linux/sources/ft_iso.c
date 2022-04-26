#include <fdf.h>

int iso(int x, int y, int z, int check)
{
    int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    x = (previous_x - previous_y) * cos(0.523599);
    y = -z + (previous_x + previous_y) * sin(0.523599);
    if (check)
        return (y);
    return (x);
}