#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 3)
        return (0);

    int width = atoi(av[1]);
    int height = atoi(av[2]);

    int y = 0;
    while (y < height)
    {
        int x = 0;
        while (x < width)
        {
            // Top or bottom row
            if (y == 0 || y == height - 1)
            {
                if (x == 0 || x == width - 1)
                    putchar('o');
                else
                    putchar('-');
            }
            // Middle rows
            else
            {
                if (x == 0 || x == width - 1)
                    putchar('|');
                else
                    putchar(' ');
            }
            x++;
        }
        putchar('\n'); // Newline at the end of each row
        y++;
    }

    return (0);
}