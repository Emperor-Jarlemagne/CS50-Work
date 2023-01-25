# include <cs50.h>
# include <stdlib.h>
# include <stdio.h>

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    //If number is less than root than search to the left (smaller side)
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    //If number is greater than root search right side (greater side)
    else if(number > tree->number)
    {
        return search(tree->right, number):
    }
    //If number is equal to root - return true!
    else // [if(number == tree->number) this part is unnecessary]
    {
        return true;
    }
}