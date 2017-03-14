#include <cstdio>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n;
int forest[501][501];
int dp[501][501];

int f(int x,int y)
{
	int &ret=dp[y][x];
	if(ret!=-1) return ret;

	ret=0;
	int cur=forest[y][x];
	forest[y][x]=0;

	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(nx>=0 && ny>=0 && nx<n && ny<n){
			if(cur < forest[ny][nx]) ret=MAX(ret,f(nx,ny));
		}
	}
	forest[y][x]=cur;
	return ret+=1;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) dp[i][j]=-1;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d",&forest[i][j]);

	int ans=-987654321;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans=MAX(ans,f(i,j));

	printf("%d\n",ans);
}