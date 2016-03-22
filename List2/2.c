#include "stdio.h"
#include "stdlib.h"

void sort(unsigned int *p1, unsigned int *p2)
{
i_love_goto:
    for(unsigned int *p = p1; p + 1 < p2; ++ p)
    {
        if(*p > *(p + 1))
        {
            *p          ^= *(p + 1);
            *(p + 1)    ^= *p;
            *p          ^= *(p + 1);
            goto i_love_goto;
        }
    }
}

int main(void)
{
    unsigned int data[5] = {5, 3, 2, 1, 4};
    sort(data, data + 5);
    for(size_t d = 0; d < 5; ++ d)
        printf("%d ", data[d]);

    puts("");
    return 0;
}
