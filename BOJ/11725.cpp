#include <cstdio>
#include <vector>

using namespace std;

int n;
int parent[100005];
vector<int> g[100005];

void dfs(int cur, int par)
{
    parent[cur] = par;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int nxt = g[cur][i];
        if(parent[nxt] == -1){
            dfs(nxt, cur);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= n; ++i) parent[i] = -1;
    dfs(1, 0);
    for(int i = 2; i <= n; ++i) printf("%d\n",parent[i]);
}