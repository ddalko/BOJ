#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int s,d;
int n,m,k;
int dist[501];
int g[501][501];

int dijkstra(int src)
{
	priority_queue<pair<int,int> > pq;
	for(int i = 0; i < n; ++i) dist[i] = INF;
	dist[src] = 0;

	pq.push(make_pair(0, src));

	while(pq.size()){
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for(int nxt = 0; nxt < n; ++nxt)
		{
			if(g[here][nxt] != -1){
				int nextCost = cost + g[here][nxt];
				if(dist[nxt] > nextCost){
					dist[nxt] = nextCost;
					pq.push(make_pair(-nextCost, nxt));
				}
			}
		}
	}

	return dist[d];
}

void backTrack(int dst)
{
	queue<int> q;
	q.push(dst);

	while(q.size())
	{
		int there = q.front();
		q.pop();

		for(int t = 0; t < n; ++t){
			if(g[t][there] != -1){
				if(dist[there] == dist[t] + g[t][there]){
					g[t][there] = -1;
					q.push(t);
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d %d",&n,&m), n != 0 || m != 0){
		scanf("%d %d",&s,&d);
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = -1;
		for(int i = 0; i < m; ++i){
			int u,v,p;
			scanf("%d %d %d",&u,&v,&p);
			g[u][v] = p;
		}
		int minDist = dijkstra(s);
		backTrack(d);
		printf("%d\n",(dijkstra(s) == INF) ? -1 : dijkstra(s));
	}
}
