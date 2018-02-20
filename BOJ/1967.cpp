#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

int idx, M;
int n;
bool visited[10005];
vector<pii> g[10005];

void dfs(int node, int dist)
{
    visited[node] = true;

    if(dist > M){
        M = dist;
        idx = node;
    }

    for(int i = 0; i < (int)g[node].size(); ++i){
        int nxt = g[node][i].first;
        int cost = g[node][i].second;
        if(!visited[nxt]){
            dfs(nxt, dist + cost);
        }
    }
}

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].eb(mp(b, c));
        g[b].eb(mp(a, c));
    }
    
    for(int i = 0; i <= n; ++i) visited[i] = false;
    M = -1e9;
    dfs(1, 0);
    for(int i = 0; i <= n; ++i) visited[i] = false;
    M = -1e9;
    dfs(idx, 0);
    printf("%d\n",M);
}