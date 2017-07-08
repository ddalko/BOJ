#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);

    int i;
    for(i = 1; i * i < n; ++i);

    for(; i >= 1; ++i){
        if(n % i == 0){
            printf("%d %d\n", n / i, i);
            return 0;
        }
    }
}