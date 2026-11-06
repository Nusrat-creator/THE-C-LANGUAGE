#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned long count[256] = {0};
    int i;
    int j;
    unsigned int c;
    unsigned char ch;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            ch = (unsigned char)argv[i][j];

            if (ch != '"')
            {
                count[ch]++;
            }

            j++;
        }
        i++;
    }

    c = 0;
    while (c < 256)
    {
        if (count[c] != 0)
        {
            printf("%c:%lu\n", (int)c, count[c]);
        }
        c++;
    }

    return 0;
}
