#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    char chars[2];
    int ints[2];
    double doubles[2];
    char *pc = chars;
    int *pi = ints;
    double *pd = doubles;

    printf("Before: pc = %p, pi = %p, pd = %p\n",
           (void *)pc, (void *)pi, (void *)pd);
    pc++;
    pi++;
    pd++;
    printf("After:  pc = %p, pi = %p, pd = %p\n",
           (void *)pc, (void *)pi, (void *)pd);
    printf("Bytes:  pc = %" PRIuPTR ", pi = %" PRIuPTR ", pd = %" PRIuPTR "\n",
           (uintptr_t)pc - (uintptr_t)chars,
           (uintptr_t)pi - (uintptr_t)ints,
           (uintptr_t)pd - (uintptr_t)doubles);

    return 0;
}
