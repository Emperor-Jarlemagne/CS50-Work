#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row ++)
    {
        for (int space = height - row - 1; space > 0; space --)
        {
            printf("  ");
        }
        for (int hash = 0; hash < row +1; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int next_hash = 0; next_hash < row + 1; next_hash++)
        {
            printf("#");
        }
        printff("\n");
    }
}