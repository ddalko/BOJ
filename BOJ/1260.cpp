#include <bits/stdc++.h>
using namespace std;

int n, m;
bool g[1005][1005];
bool visited[1005];

void dfs(int u)
{
	visited[u] = true;
	printf("%d ", u);

	for(int v = 1; v <= n; ++v){
		if(g[u][v] && !visited[v]){
			dfs(v);
		}
	}
}

int main()
{
	int V;
	scanf("%d %d %d",&n,&m,&V);

	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d",&u,&v);
		g[u][v] = g[v][u] = 1;
	}


	dfs(V);
	puts("");
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(V);
	visited[V] = true;

	while(!q.empty()){
		int u = q.front(); q.pop();
		printf("%d ", u);

		for(int v = 1; v <= n; ++v){
			if(g[u][v] && !visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}