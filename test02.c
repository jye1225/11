#include <stdio.h>

int main(void)
{
    int i = 4;
    int *pi = &i;
    unsigned char *pc = (unsigned char *)&i;

    printf("%d, %d, %u\n", i, *pi, (unsigned int)*pc);

    i = 300;
    printf("%d, %d, %u\n", i, *pi, (unsigned int)*pc);

    return 0;
}
