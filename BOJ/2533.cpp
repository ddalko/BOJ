#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

int n;
int dp[MAXN+5][2];
vector<int> g[MAXN+5];

void dfs(int cur, int parent)
{
    dp[cur][0] = 0; dp[cur][1] = 1;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int nxt = g[cur][i];
        if(nxt != parent){
            dfs(nxt, cur);
            dp[cur][0] += dp[nxt][1];
            dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n-1; ++i){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, -1);
    printf("%d\n",min(dp[1][0], dp[1][1]));
}