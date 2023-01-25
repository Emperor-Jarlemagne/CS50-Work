# include <stdio.h>
# include <stdlib.h>
# include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    //list of size
    node *list = NULL;

    //Add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    //Update list to point to new node
    list = n;

    //Add a number to the list
    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    //Add another number to list
    n = malloc(sizeof(node))
    if(n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n-> = NULL;
    list->next->next = n;

    //Print numbers
    for (node *tmp = list; tmp !=NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number)
    }
    //Free List (when there are linked lists, the computer does not know how to follow your pointers)
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return: 0;
}