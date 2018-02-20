#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);

    int d = 2;
    for(int i = 2; i * i <= n; ++i){
        while(n % i == 0){
            printf("%d\n", i);
            n = n / i;
        }
    }
    if(n > 1) printf("%d\n", n);
}