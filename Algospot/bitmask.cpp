#include <cstdio>

int main()
{
    int n = 1 << 7 | 1 << 3;
    printf("%d\n",__builtin_popcount(n));
    printf("%d\n",__builtin_ctz(n));
}