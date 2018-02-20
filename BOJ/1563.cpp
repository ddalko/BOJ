#include <cstdio>

const int MOD = 1000000;

int n;
int dp[1005][2][3];

int f(int idx, int l, int a)
{
    if(idx == n) return 1;
    
    int &ret = dp[idx][l][a];
    if(ret != -1) return ret;

    ret = f(idx+1, l, 0);
    if(l == 0) ret += f(idx+1, 1, 0);
    if(a < 2) ret += f(idx+1, l, a+1);
    return ret %= MOD;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i <= n; ++i) for(int j = 0; j < 2; ++j) for(int k = 0; k < 3; ++k) dp[i][j][k] = -1;
    printf("%d\n",f(0,0,0));
}