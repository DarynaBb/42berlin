#include "../fractol.h"

void put_pixel(t_img *img, int x, int y, int color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) // Bounds check
        return;

    char *pixel = img->addr + (y * img->line_length) + (x * (img->bpp / 8));

    if (img->endian == 0)  // Little Endian (Most common)
    {
        pixel[0] = color & 0xFF;           // Blue
        pixel[1] = (color >> 8) & 0xFF;    // Green
        pixel[2] = (color >> 16) & 0xFF;   // Red
    }
    else  // Big Endian
    {
        pixel[0] = (color >> 16) & 0xFF;   // Red
        pixel[1] = (color >> 8) & 0xFF;    // Green
        pixel[2] = color & 0xFF;           // Blue
    }
}


void sierpinski(t_img *img, int x, int y, int size, int depth)
{
    if (depth == 0)
    {
        for (int dy = 0; dy < size; dy++)
        {
            for (int dx = 0; dx < size - dy; dx++)
            {
                put_pixel(img, x + dx - dy / 2, y - dy, 0xFFFFFF);
            }
        }
        return;
    }

    int half = size / 2;

    // Recursively draw 3 smaller triangles
    sierpinski(img, x, y, half, depth - 1);
    sierpinski(img, x + half, y, half, depth - 1);
    sierpinski(img, x + half / 2, y - half, half, depth - 1);
}
