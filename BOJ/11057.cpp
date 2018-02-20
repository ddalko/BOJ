#include <cstdio>

const int MOD = 10007;

int n;
int dp[2][10];

int f(int idx, int b)
{
    if(idx == n) return 1;

    int& ret = dp[idx][b];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 10; ++i)
    {
        if(b <= i) ret += f(idx+1, i);
    }
    return ret %= MOD;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i <= n; ++i) for(int j = 0; j < 10; ++j) dp[i][j] = -1;
    
    printf("%d\n", f(0, 0));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
}