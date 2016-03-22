#include <stdlib.h>

size_t gcd(size_t x, size_t y)
{
    if(x == 0) return y;
    if(y == 0) return x;

    if(x < y)
        return gcd(x, y - x);

    else
        return gcd(x - y, y);
}
