#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

int N, M, W;
vector<pii> G[505];

bool f(int src)
{
	vector<int> dist(N, INF);
	dist[src] = 0;
	bool updated;

	for(int iter = 0; iter < N; ++iter){
		updated = false;
		for(int u = 0; u < N; ++u){
			for(int i = 0; i < (int)G[u].size(); ++i){
				int v = G[u][i].first;
				int w = G[u][i].second;

				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					updated = true;
				}
			}
		}
		if(!updated) break;
	}

	if(updated) return true;
	return false;
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d",&N,&M,&W);
		for(int i = 0; i < N; ++i) G[i].clear();

		int src = 0;
		int s, e, t;
		for(int i = 0; i < M; ++i){
			scanf("%d %d %d",&s,&e,&t);
			G[s-1].push_back({e-1, t});
			G[e-1].push_back({s-1, t});
			if(!src) src = s-1;
		}

		for(int i = 0; i < W; ++i){
			scanf("%d %d %d",&s,&e,&t);
			G[s-1].push_back({e-1, -t});
		}

		if(f(src)) puts("YES");
		else puts("NO");
	}
}