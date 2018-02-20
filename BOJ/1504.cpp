#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

const int INF = 1e9;

int n, e;
int x1, x2;
int dist[805];
vector<pii> g[805];

int dijkstra(int src, int dst)
{
   priority_queue<pii, vector<pii>, greater<pii> > pq;
   for(int i = 0; i <= n; ++i) dist[i] = INF;

   dist[0] = dist[src] = 0;
   pq.push(mp(0, src));

   while(!pq.empty()){
      int cur = pq.top().second;
      int cost = pq.top().first;
      pq.pop();

      if(dist[cur] < cost) continue;

      for(int i = 0; i < (int)g[cur].size(); ++i){
         int nxt = g[cur][i].first;
         int nxtCost = g[cur][i].second + cost;

         if(dist[nxt] > nxtCost){
            dist[nxt] = nxtCost;
            pq.push(mp(nxtCost, nxt));
         }
      }
   }
   return dist[dst];
}

int main()
{
   scanf("%d %d",&n,&e);
   for(int i = 0; i < e; ++i){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      g[a].eb(mp(b, c));
      g[b].eb(mp(a, c));
   }
   scanf("%d %d",&x1,&x2);

   long long a1 = (long long)dijkstra(1, x1) + dijkstra(x1, x2) + dijkstra(x2, n);
   long long a2 = (long long)dijkstra(1, x2) + dijkstra(x2, x1) + dijkstra(x1, n);
   long long ans = min(a1, a2);

   (ans >= INF) ? puts("-1") : printf("%lld\n",ans);
}
