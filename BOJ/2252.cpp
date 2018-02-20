#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[32005];
vector<int> g[32005];
vector<int> ans;

void dfs(int cur)
{
    visited[cur] = true;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int nxt = g[cur][i];

        if(!visited[nxt]) dfs(nxt);
    }

    ans.push_back(cur);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i){
        if(!visited[i]) dfs(i);
    }

    for(int i = (int)ans.size()-1; i >= 0; --i){
        printf("%d ",ans[i]);
    }
}