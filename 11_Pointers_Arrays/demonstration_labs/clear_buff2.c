#include<stdio.h>

int main(void)
{
    char c;
    c = getchar();
    printf("You entered %c\n",c);

    while ((c = getchar()) != '\n' && c != EOF){}
}