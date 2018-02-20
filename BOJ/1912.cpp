#include <cstdio>
#include <algorithm>

int main()
{
    int n;
    long long a, x = 0, ans = -1e15;
    for(scanf("%d",&n);n--;){
        scanf("%lld",&a);
        a = std::max(a, a + x);
        x = a;
        ans = std::max(a, ans);
    }
    printf("%lld\n",ans);
}