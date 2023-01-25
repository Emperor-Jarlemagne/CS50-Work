# include <cs50.h>
# include <stdio.h>

int main(void)
{
    int numbers[] = {2,6,4,5,1,3};

    for (int i =0; i < 6; i++)
    {
        if (numbers[i] == 1)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not Found!\n");
    return 1;
}