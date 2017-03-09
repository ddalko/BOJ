#include <cstdio>
#include <algorithm>

using namespace std;

int p[1002];
int dp[1002];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",p+i);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i] = max(dp[i], dp[i-j]+p[j]);
        }
    }

    printf("%d\n",dp[n]);
}
