#include <cstdio>

int main()
{
    int n, m, ans;
    int a, b;
    int smin = 1e9, min = 1e9;

    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; ++i){
        scanf("%d %d",&a,&b);
        if(smin > a) smin = a;
        if(min > b) min = b;
    }

    if(smin >= 6 * min){
        ans = n * min;
    }else{
        ans = smin * (n / 6);
        ans += (smin < (n%6)*min) ? smin : (n % 6) * min;
    }
    printf("%d\n",ans);
}