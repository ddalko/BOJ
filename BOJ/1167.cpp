#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int v;
int root; int dist;
bool visited[100005];
vector<pii> g[100005];

void dfs(int cur, int cost)
{
    visited[cur] = true;
    if(cost > dist){
        dist = cost;
        root = cur;
    }

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int nxt = g[cur][i].first;
        int nxtCost = g[cur][i].second;
        if(!visited[nxt]){
            dfs(nxt, cost + nxtCost);
        }
    }
}

int main()
{
    scanf("%d",&v);
    for(int i = 0; i < v; ++i){
        int a, b, c;
        scanf("%d",&a);

        while(scanf("%d",&b), b != -1){
            scanf("%d",&c);
            g[a].emplace_back(mp(b, c));
            g[b].emplace_back(mp(a, c));
        }
    }
    for(int i = 0; i <= v; ++i) visited[i] = false;
    root = -1; dist = -1e9;
    dfs(1, 0);
    
    for(int i = 0; i <= v; ++i) visited[i] = false;
    dist = -1e9;
    dfs(root, 0); 
    printf("%d\n", dist);
}