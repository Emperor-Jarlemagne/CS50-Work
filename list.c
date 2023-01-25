# include <stdio.h>
# include <stdlib.h>

int main(void)
{
    //Dynamically allocate an area of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    //Assign 3 numbers to that array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //Time Passes

    //Resize old array to be of size 4
    int *tmp = malloc(4 * sizeof(int));
    if(tmp ==NULL)
    {
        free(list);
        return 1;
    }

    //Copy numbers from old array into new array (if realloc is used in step above, next two steps are no longer necessary)
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    //Add 4th number to old array
    tmp[3] = 4;

    //Free old array
    free(list);

    //Remember new array
    list = tmp;

    //Print new array
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    //free new array
    free(list);
    return 0;

}