#include <bits/stdc++.h>

using namespace std;

const int MAXN=10000;

int n,m;
int s,e;
int cnt;
int dist[MAXN+2];
int vis[MAXN+2];
vector<pair<int,int> > g[MAXN+2];

int findLongest(int cur)
{
	int &ret=dist[cur];
	if(ret!=-1) return ret;

	ret=0;
	for(int nxt=0;nxt<g[cur].size();++nxt){
		ret=max(ret,findLongest(g[cur][nxt].first)+g[cur][nxt].second);
	}
	return ret;
}

int dfs(int x) {
	vis[x] = true;
	for (int i = 0; i < g[x].size(); ++i) {
		if (dist[x] == dist[g[x][i].first] + g[x][i].second) {
			++cnt;
			if (!vis[g[x][i].first]) {
				dfs(g[x][i].first);
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;++i) dist[i]=-1;
	for(int i=0;i<m;++i){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a].push_back(make_pair(b,c));
	}
	scanf("%d %d",&s,&e);

	int ans1=findLongest(s);
	int ans2=0;
	
	dfs(s);
	ans2 = cnt;
	printf("%d\n%d\n",ans1,ans2);
}