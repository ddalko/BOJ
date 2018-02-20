#include <cstdio>

int n;
int a, b, x;

int main()
{
    a = -1e9; b = 1e9;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
        scanf("%d",&x);
        if(a < x) a = x;
        if(b > x) b = x;
    }
    printf("%d\n",a * b);
}