#include <cstdio>

int n;
int a[1005];
int dp[1005];

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i){
        scanf("%d",a+i);
        int maxi = -1e9; int mini = 1e9;

        for(int j = 0; j < i; ++j){
            if(maxi < a[j]) maxi = a[j];
            if(mini > a[j]) mini = a[j];
            if(dp[i+1] < dp[j] + maxi - mini) dp[i+1] = dp[j] + maxi - mini;
        }
    }
    printf("%d\n", dp[n]);
}