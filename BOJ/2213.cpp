#include <cstdio>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) ((a) < 0 ? (-(a)):(a))

const int MAXN = 10001;

int n;
int w[MAXN+1];
int dp[MAXN+2][2];
bool ans[MAXN+1];
vector<int> g[MAXN+1];

int f(int cur,int isInd,int parent)
{
	int& ret = dp[cur][isInd];
	if(ret != -1) return ret;

	ret = (isInd) ? w[cur] : 0;
	for(int nxt = 1; nxt <= n; ++nxt){
		if(g[cur][nxt] && parent != nxt){
			if(isInd) ret += f(nxt, !isInd, cur);
			else ret += MAX(f(nxt, isInd, cur),f(nxt, !isInd, cur));
		}
	}
	return ret;
}

void backTrack(int cur,bool Ind,int parent)
{
	for(int nxt = 1; nxt <= n; ++nxt){
		if(g[cur][nxt] && parent != nxt){
			if(Ind == false){
				if(dp[nxt][1] > dp[nxt][0]) {
					ans[nxt] = 1;
					backTrack(nxt, true, cur);
				}
				else backTrack(nxt, false, cur);
			}else backTrack(nxt, false, cur);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",w+i), dp[i][0] = dp[i][1] = -1;
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a][b] = g[b][a] = 1;
	}
	int sol = 0;
	printf("%d\n",sol = MAX(f(1,0,0),f(1,1,0)));

	if(sol == dp[1][0]) backTrack(1, 0, 0);
	else {
		ans[1] = 1;
		backTrack(1, 1, 0);
	}

	for(int i = 1; i <= n; ++i) if(ans[i]) printf("%d ",i);
	printf("\n");
}