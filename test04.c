#include <stdio.h>
#define SIZE 5

int main(void)
{
    int grade[SIZE];
    const int *p = grade;
    int i;
    double sum = 0;

    for (i = 0; i < SIZE; i++)
    {
        printf("input value (%d): ", i);
        if (scanf("%d", &grade[i]) != 1)
            return 1;
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("grade[%d] = %d\n", i, *(p + i));
        sum += *(p + i);
    }
    printf("average : %g\n", sum / SIZE);

    return 0;
}
