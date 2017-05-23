#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int coin;
int dp[10001];

int main()
{
    scanf("%d %d",&n,&k);
    for(int j = 0; j <= k; ++j) dp[j] = 1e9;

    dp[0] = 0;
    for(int i = 0; i < n; ++i){    
        scanf("%d",&coin);
        for(int j = coin; j <= k; ++j){
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }
    printf("%d\n",dp[k]==1e9 ? -1 : dp[k]);
}