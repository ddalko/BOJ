#include <cstdio>

bool g[1001][1001];
bool visited[1001];

int V,E;

void dfs(int node)
{
	visited[node]=1;
	for(int i=1;i<=V;++i) if(g[node][i] && !visited[i]) dfs(i);
}

int main()
{
	scanf("%d %d",&V,&E);

	for(int i=0;i<E;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a][b] = g[b][a] = 1;
	}

	int ans=0;
	for(int i=1;i<=V;++i){
		if(!visited[i]) {
			ans++;
			dfs(i);
		}
	}
	printf("%d\n",ans);
}