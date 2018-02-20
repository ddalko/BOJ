#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n;
int w[10005];
int dp[10005][3];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d", w+i);

    for(int i = 0; i <= n; ++i) for(int j = 0; j < 3; ++j) dp[i][j] = -INF;

    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
            if(j < 2) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + w[i]);
        }
    }
    printf("%d\n",max(dp[n][0], max(dp[n][1], dp[n][2])));
}