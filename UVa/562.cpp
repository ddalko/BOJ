#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int m;
bool dp[50005];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d",&m);
        memset(dp, 0, sizeof(dp));

        dp[0] = true;
        int money = 0; int coin = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d",&coin);
            for(int j = money; j >= 0; --j){
                if(dp[j]) dp[j + coin] = dp[j];
            }
            money += coin;
        }

        int ans = 1e9;
        for(int i = 0; i <= money; ++i){
            if(dp[i]) ans = min(ans, abs(2*i - money));
        }
        printf("%d\n",ans);
    }
}