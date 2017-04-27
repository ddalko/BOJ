#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

int n, m;
int s, d;
int dist[505];
int g[505][505];

int dijkstra(int src)
{
	for(int i = 0; i < n; ++i) dist[i] = 1e9;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dist[src] = 0;
	pq.push(mp(0, src));

	while(!pq.empty()){
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if(dist[cur] < cost) continue;

		for(int i = 0; i < n; ++i){
			if(g[cur][i] != -1){
				int nxt = i;
				int nxtCost = cost + g[cur][i];

				if(dist[nxt] > nxtCost){
					dist[nxt] = nxtCost;
					pq.push(mp(nxtCost, nxt));
				}
			}
		}
	}
	return dist[d];
}

void backtrack(int dst)
{
	queue<int> q;
	q.push(dst);

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int src = 0; src < n; ++src){
			if(g[src][cur] != -1){
				if(dist[cur] == dist[src] + g[src][cur]){
					g[src][cur] = -1;
					q.push(src);
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d %d",&n,&m), n != 0 || m != 0){
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = -1;

		scanf("%d %d",&s,&d);
		for(int i = 0; i < m; ++i){
			int u, v, p;
			scanf("%d %d %d",&u,&v,&p);
			g[u][v] = p;
		}
		dijkstra(s);
		backtrack(d);
		int ans = dijkstra(s);
		(ans != 1e9) ? printf("%d\n",ans) : puts("-1");
	}
}