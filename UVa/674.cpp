#include <cstdio>

int M;
int C[4] = {5, 10, 25, 50};
int dp[7490];

int main()
{
    for(int i = 0; i <= 7489; ++i) dp[i] = 1;
    
    for(int i = 0; i < 4; ++i){
        for(int j = C[i]; j <= 7489; ++j){
            dp[j] += dp[j - C[i]];
        }
    }

    while(scanf("%d",&M) != -1){
        printf("%d\n",dp[M]);
    }    
}