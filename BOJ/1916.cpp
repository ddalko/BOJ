#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;

int n, m;
int s, d;
int dist[1005];
vector<pii> g[1005];

int dijkstra()
{
    priority_queue<pii> pq;

    dist[s] = 0;
    pq.push(mp(0, s));

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < (int)g[cur].size(); ++i){
            int nxt = g[cur][i].first;
            int nxtCost = cost + g[cur][i].second;

            if(dist[nxt] > nxtCost){
                dist[nxt] = nxtCost;
                pq.push(mp(nxtCost, nxt));
            }
        }
    }
    return dist[d];
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].pb(mp(b, c));
    }
    for(int i = 0; i <= n; ++i) dist[i] = 1e9;

    scanf("%d %d",&s,&d);
    int ans = dijkstra();
    printf("%d\n",ans);
}