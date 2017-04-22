#include <cstdio>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n;
int g[16][16];
int dp[16][1<<16];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d",&g[i][j]);

    for(int i = 0; i < n; ++i) for(int j = 0; j < (1<<n); ++j) dp[i][j] = 1e9;

    dp[0][1] = 0;
    for(int state = 0; state < (1<<n); ++state){
        for(int start = 0; start < n; ++start){
            if(state & (1<<start)){
                for(int nxt = 0; nxt < n; ++nxt){
                    if(!(state & (1<<nxt))){
                        if(g[start][nxt]){
                            dp[nxt][state | (1<<nxt)] = min(dp[nxt][state | (1<<nxt)], dp[start][state] + g[start][nxt]);
                        }
                    }
                }
            }
        }
    }

    int ans = 1e9;
    for(int i = 0; i < n; ++i){
        ans = min(ans, dp[i][(1<<n)-1] + g[i][0]);
    }
    printf("%d\n",ans);
}