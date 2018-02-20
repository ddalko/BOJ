#include <cstdio>
#include <vector>

using namespace std;

int v, e;
int order;
int d[10005];
bool cutVertex[10005];
vector<int> g[10005];

int dfs(int cur, bool isRoot)
{
    d[cur] = order++;
    int ret = d[cur];

    int children = 0;
    for(int i = 0; i < (int)g[cur].size(); ++i){
        int nxt = g[cur][i];

        if(d[nxt] == -1){
            children++;
            int subtree = dfs(nxt, 0);
            if(!isRoot && subtree >= d[cur]) cutVertex[cur] = true;
            ret = min(ret, subtree);
        }else ret = min(ret, d[nxt]);
    }

    if(isRoot) cutVertex[cur] = (children >= 2);
    return ret;
}

int main()
{
    scanf("%d %d",&v,&e);
    for(int i = 0; i < e; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= v; ++i) d[i] = -1;

    order = 0;
    for(int i = 1; i <= v; ++i){
        if(d[i] == -1) dfs(i, 1);
    }

    int ans = 0;
    for(int i = 1; i <= v; ++i) ans += (cutVertex[i]) ? 1 : 0;
    printf("%d\n",ans);
    for(int i = 1; i <= v; ++i) if(cutVertex[i]) printf("%d ",i);
    return 0;
}