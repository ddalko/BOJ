#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int p[1005];
int dp[1005];

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%d",p+i);

    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i + j <= n) dp[i + j] = max(dp[i + j], dp[i] + p[j]);
        }
    }
    printf("%d\n",dp[n]);
}