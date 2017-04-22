#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

int v, e;
int dist[20005];
vector<pii> g[20005]; 

void dijkstra(int src)
{
    for(int i = 1; i <= v; ++i) dist[i] = 1e9;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[src] = 0;
    pq.push(mp(0, src));

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
}

int main()
{
    int k;
    scanf("%d %d",&v,&e);
    scanf("%d",&k);
    
    for(int i = 0; i < e; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].eb(mp(b, c));
    }
    dijkstra(k);
    for(int i = 1; i <= v; ++i) dist[i]==1e9 ? puts("INF") : printf("%d\n",dist[i]);
}