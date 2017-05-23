#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char inp[1005][1005];
int dp[1005][1005];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s",inp[i]);

    int ans = -1e9;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(inp[i-1][j-1] == '1') dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans * ans);
}