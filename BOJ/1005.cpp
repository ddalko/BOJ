#include <bits/stdc++.h>

using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))

const int MAXN=1000;

int n,k,w;
int d[MAXN+2];
int dp[MAXN+2];
bool g[MAXN+2][MAXN+2];

int dfs(int cur)
{
	if(dp[cur]!=-1) return dp[cur];

	dp[cur]=0;
	for(int nxt=1;nxt<=n;++nxt){
		if(g[nxt][cur] && dp[cur]<dfs(nxt)) dp[cur]=dfs(nxt);
	}
	return dp[cur]=dp[cur]+d[cur];
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&k);
		for(int i=0;i<=n;++i) dp[i]=-1;
		for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) g[i][j]=0;
		for(int i=1;i<=n;++i) scanf("%d",d+i);
		
		for(int i=0;i<k;++i){
			int a,b;
			scanf("%d %d",&a,&b);
			g[a][b]=1;
		}
		scanf("%d",&w);
		printf("%d\n",dfs(w));
	}
}