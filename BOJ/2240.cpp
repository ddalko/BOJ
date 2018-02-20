#include <cstdio>
#include <algorithm>

using namespace std;

int t, w, x;
int a[2];
int dp[2][35][2];

int main()
{
    scanf("%d %d",&t,&w);

    for(int i = 0; i < t; ++i){
        scanf("%d",&x);
        a[x-1] = 1; a[!(x-1)] = 0;
        for(int j = 0; j <= w; ++j){
            for(int k = 0; k < 2; ++k){
                dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k], dp[i%2][j][k] + a[k]);
                dp[(i+1)%2][j+1][!k] = max(dp[(i+1)%2][j+1][!k], dp[i%2][j][k] + a[k]);
            }
        }
    }
    
    int ans = -1e9;
    for(int i = 0; i <= w; ++i) ans = max(ans, max(dp[t%2][i][0], dp[t%2][i][1]));
    printf("%d\n",ans);
}