#include <cstdio>
#include <cstring>

using namespace std;

bool flag;
int cnt;
int n, m;
bool g[105][105];
int v[105];
bool t[105];

void dfs(int cur)
{
    if(cur == n) return;
    v[cur] = cnt++;
    
    for(int nxt = 1; nxt <= n; ++nxt){
        if(g[cur][nxt]){
            if(v[nxt] == -1) dfs(nxt);
            else if(v[cur] >= v[nxt] && !t[nxt]) flag = true;
        }
    }

    t[cur] = 1;
}

int main()
{
    scanf("%d",&n);
    memset(v, -1, sizeof(v));

    for(int i = 0; i < n; ++i){
        scanf("%d",&m);
        int u = i+1;
        for(int i = 0; i < m; ++i){
            int v;
            scanf("%d",&v);
            g[u][v] = 1;
        }
    }

    flag = false; cnt = 0;
    dfs(1);
    
    if(flag) puts("CYCLE");
    else puts("NO CYCLE");
}