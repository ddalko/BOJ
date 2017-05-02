#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, M;
int m[101];
int c[101];
int dp[2][10005];

int main()
{
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i) scanf("%d",m+i);
    for(int i = 0; i < N; ++i) scanf("%d",c+i);
    for(int i = 0; i < 2; ++i) for(int j = 0; j <= N*100; ++j) dp[i][j] = -INF;

    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= N*100; ++j){
            dp[(i+1)%2][j] = max(dp[(i+1)%2][j], dp[i%2][j]);
            if(N*100 >= j+c[i]) dp[(i+1)%2][j+c[i]] = max(dp[(i+1)%2][j+c[i]], dp[i%2][j] + m[i]);
        }
    }
    
    for(int i = 0; i <= N*100; ++i){
        if(dp[N%2][i] >= M) {
            printf("%d\n",i);
            return 0;
        }
    }
}