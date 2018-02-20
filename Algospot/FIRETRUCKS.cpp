#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

int v, e, n, m;
int dist[1005];
vector<pii> g[1005];

void dijkstra()
{
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    dist[0] = 0;
    pq.push(mp(0, 0));

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < (int)g[cur].size(); ++i){
            int nxt = g[cur][i].first;
            int nxtCost = dist[cur] + g[cur][i].second;

            if(dist[nxt] > nxtCost){
                dist[nxt] = nxtCost;
                pq.push(mp(nxtCost, nxt));
            }
        }
    }
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d %d %d",&v,&e,&n,&m);
        for(int i = 0; i <= v; ++i) g[i].clear();
        for(int i = 0; i <= v; ++i) dist[i] = 1e9;

        for(int i = 0; i < e; ++i){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            g[a].eb(mp(b, c));
            g[b].eb(mp(a, c));
        }
        
        vector<int> fire;
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d",&x);
            fire.eb(x);
        }

        for(int i = 0; i < m; ++i){
            int x;
            scanf("%d",&x);
            g[0].eb(mp(x, 0));
        }

        dijkstra();   

        int ans = 0;
        for(int i = 0; i < (int)fire.size(); ++i){
            ans += dist[fire[i]];
        }
        printf("%d\n",ans);
    }
}