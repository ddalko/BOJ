#include <bits/stdc++.h>
using namespace std;

int n;
int arr[31];
bool dp[2][15505];

int main()
{
    scanf("%d",&n);
    int w = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr+i);
        w += arr[i];
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= w; ++j){
            if(dp[i%2][j]){
                dp[(i+1)%2][j] = dp[i%2][j];
                int left = abs(j-arr[i]);
                int right = j+arr[i];
                if(left <= 15000) dp[(i+1)%2][left] = dp[i%2][j];
                if(right <= 15000) dp[(i+1)%2][right] = dp[i%2][j];
            }
        }
    }

    int m, q;
    for(scanf("%d",&m);m--;){
        scanf("%d",&q);
        if(q <= 15000 && dp[n%2][q]) printf("Y ");
        else printf("N ");
    }
}