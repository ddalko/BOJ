
int main()
{
    while(scanf("%d %d",&n,&m) != -1)
    {   
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d",&g[i][j]);
        for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = 1e18;

        for(int i = 0; i < n; ++i) dp[i][0] = 0;      

        for(int j = 0; j < m; ++j){
            for(int i = 0; i < n; ++i){
                dp[(i+n-1)%n][j+1] = min(dp[(i+n-1)%n][j+1], dp[i][j] + g[i][j]);
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + g[i][j]);
                dp[(i+1)%n][j+1] = min(dp[(i+1)%n][j+1], dp[i][j] + g[i][j]);
            }
        }

        long long ans = 1e18;
        for(int i = 0; i < n; ++i) ans = min(ans, dp[i][m]);
        for(int i = 0; i < n; ++i) if(dp[i][m] == ans) f[i][m] = 1;

        for(int j = m-1; j >= 0; --j){
            for(int i = 0; i < n; ++i){
                int tt = g[i][j] + dp[i][j];
                if(f[i][j+1] && tt == dp[i][j+1]) f[i][j] = 1;
                if(f[(i+n-1)%n][j+1] && tt == dp[(i+n-1)%n][j+1]) f[i][j] = 1;
                if(f[(i+1)%n][j+1] && tt == dp[(i+1)%n][j+1]) f[i][j] = 1;
            }
        }

        int tmp = 0;
        for(int j = 0; j < m; ++j){
            for(int i = 0; i < n; ++i){
                if(f[i][j] && f[]) {
                    if(j == 0 || (tmp+n-1)%n == i || tmp == i || (tmp+1)%n == i){
                        tmp = i;
                        printf("%d ",i+1);
                        break;
                    }
                }
            }
        }
        puts("");
        printf("%lld\n",ans);
    }
}