# include <cs50.h>
# include <stdio.h>
# include <string.h>

int main (void)
{
    string names[] = {"Pizza", "Burgers", "stirfry", "curry", "banh mi"};
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(names[i], "Frederick"))
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}