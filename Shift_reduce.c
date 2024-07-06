#include <stdio.h>
#include <stdlib.h>

#include <string.h>
char a[20], act[20], stk[30], ac[10];
int size, i = 0, j = 0, c = 0, z = 0;
void check()
{
    strcpy(ac, "Reduce to E-> ");
    for (z = 0; z < c; z++)
    {
        if (stk[z] == '4')
        {
            printf("%s4", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            printf("\n$%s\t%s\t", stk, a);
        }
    }
    for (z = 0; z < c; z++)
    {
    }
}
int main()
{
    printf("Grammar is -\nE->E+E/E*E/E \nE->id/NULL");
    // given string
    strcpy(a, "id+id*id");
    size = strlen(a);
    strcpy(act, "shift");
    printf("\nstack \t input \t action");
    printf("\n$\t%s$\t", a);
    for (i = 0; j < c; j++)
    {
        printf("%s", act);
        // pushing into the stack
        stk[i] = a[j];
        stk[i + 1] = "\0";

        a[j] = ' ';
        printf("\n$%s\t%s$\t", stk, a);
        check();
    }
    check();
    if (stk[0] == 'E' && stk[1] == '\0')
    {
        printf("Accept\n");
    }
    else
    {
        printf("Reject\n");
    }
}