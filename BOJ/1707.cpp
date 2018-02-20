#include <cstdio>
#include <vector>

using namespace std;

int v, e;
int visited[20005];
vector<int> g[20005];

bool dfs(int node, int c)
{
    visited[node] = c;

    for(int i = 0; i < (int)g[node].size(); ++i){
        if(visited[g[node][i]] == c) return false;
        if(visited[g[node][i]] == 0 && !(dfs(g[node][i], -c))) return false;
    }
    return true;
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d",&v,&e);
        for(int i = 0; i <= v; ++i) g[i].clear();
        for(int i = 0; i <= v; ++i) visited[i] = 0;

        for(int i = 0; i < e; ++i){
            int a, b;
            scanf("%d %d",&a,&b);
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }

        bool ans = true;
        for(int i = 1; i <= v; ++i){
            if(visited[i] == 0) {
                if(!dfs(i, 1)) {
                    ans = false;
                    break;
                }
            }
        }

        if(ans) puts("YES");
        else puts("NO");
    }
}