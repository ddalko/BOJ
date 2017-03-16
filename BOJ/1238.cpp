#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n,m,x;
vector<pair<int,int> > g1[1001];
vector<pair<int,int> > g2[1001];

int dist1[1001];
int dist2[1001];

void dijkstra1(int src)
{
	priority_queue<pair<int, int> > pq;
	dist1[src] = 0;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist1[here] < cost) continue;

		for(pair<int, int>& i : g1[here]){
			int there = i.second;
			int nextDist = cost + i.first;
			if(dist1[there] > nextDist){
				dist1[there] = nextDist;
				pq.push(make_pair(-nextDist,there));
			}
		}
	}
}

void dijkstra2(int src)
{
	priority_queue<pair<int, int> > pq;
	dist2[src] = 0;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist2[here] < cost) continue;

		for(pair<int, int>& i : g2[here]){
			int there = i.second;
			int nextDist = cost + i.first;
			if(dist2[there] > nextDist){
				dist2[there] = nextDist;
				pq.push(make_pair(-nextDist,there));
			}
		}
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&x);
	for(int i = 0; i < m; ++i){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g1[a].push_back(make_pair(c,b));
		g2[b].push_back(make_pair(c,a));
	}

	for(int i = 1; i <= n; ++i) dist1[i] = dist2[i] = INF;

	dijkstra1(x);
	dijkstra2(x);
	
	int ans = -1e9;
	for(int i = 1; i <= n; ++i) ans = max(ans, dist1[i] + dist2[i]);
	printf("%d\n",ans);
}