#include <stdio.h>

void swap_values(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    printf("Inside value swap: a:%d, b:%d\n", x, y);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int a = 3;
    int b = 5;

    swap_values(a, b);
    printf("After value swap: a:%d, b:%d\n", a, b);

    swap(&a, &b);
    printf("After pointer swap: a:%d, b:%d\n", a, b);

    return 0;
}
