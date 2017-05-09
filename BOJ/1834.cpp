#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);

    int ans = 0;
    for(int i = 0; i < n*n; ++i){
        if(i / n == i % n) ans += i;
    }
    printf("%d\n",ans);
}