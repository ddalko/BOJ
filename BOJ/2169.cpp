#include <cstdio>

int n, m;
int board[1005][1005];
int dp[1005][1005];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d",&board[i][j]);

    dp[0][0] = board[0][0];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i+1 < n && board[i+1][j] != 1e9){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + board[i+1][j]);
                board[i+1][j] = 
            }
        }
    }
}