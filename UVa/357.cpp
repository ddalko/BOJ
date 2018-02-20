#include <cstdio>

const int coin[4] = {5, 10, 25, 50};
long long dp[30001];

int main()
{
    for(int i = 0; i <= 30000; ++i) dp[i] = 1;

    for(int i = 0; i < 4; ++i){
        for(int j = coin[i]; j <= 30000; ++j){
            dp[j] += dp[j-coin[i]];
        }
    }

    int m;
    while(scanf("%d",&m) != -1) {
        if(dp[m] == 1) printf("There is only %lld way to produce %d cents change.\n",dp[m],m);
        else printf("There are %lld ways to produce %d cents change.\n",dp[m],m);
    }
}