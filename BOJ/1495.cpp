#include <cstdio>

#define MAX(a,b) (((a)>(b))?(a):(b))

int v[102];
int dp[101][1001];

int main()
{
	int n,s,m;
	scanf("%d %d %d",&n,&s,&m);
	for(int i=1;i<=n;++i) scanf("%d",v+i);
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) dp[i][j]=-1;

	dp[0][s]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(j+v[i]<=m&&dp[i-1][j]!=-1) dp[i][j+v[i]]=dp[i-1][j];
			if(j-v[i]>=0&&dp[i-1][j]!=-1) dp[i][j-v[i]]=dp[i-1][j];
		}
	}
	
	int ans=-1;
	for(int i=m;i>=0;--i) if(dp[n][i]!=-1) {ans=i; break;}
	printf("%d\n",ans);
}