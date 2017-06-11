#include <cstdio>

int main()
{
    int n;
    long long ans = 0;
    scanf("%d",&n);
    for(int i = 1; i < n+1; ++i){
        if(i * i > n) break;
        ans += n / i - i + 1;
    }
    printf("%lld\n",ans);
}