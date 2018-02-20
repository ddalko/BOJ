#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> g[100001];
bool visited[100001];

int bfs(int node)
{
	int ret = 0;

	queue<int> q;
	q.push(node);

	while(!q.empty()){
		int cur = q.front();
		visited[cur] = true;
		ret++;
		q.pop();

		for(int i = 0; i < (int)g[cur].size(); ++i){
			int nxt = g[cur][i];

			if(!visited[nxt]){
				q.push(nxt);
			}
		}
	}

	return ret;
}

int main()
{
	int c;
	for(scanf("%d",&c);c--;){
		scanf("%d %d",&n,&m);
		for(int i = 0; i <= n; ++i) visited[i] = false;
		for(int i = 0; i <= n; ++i) g[i].clear();

		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int ans = -1e9;
		for(int i = 1; i <= n; ++i){
			if(!visited[i])	ans = max(ans, bfs(i));
		}

		printf("%d\n", ans);
	}
}