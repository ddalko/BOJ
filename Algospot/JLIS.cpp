#include <cstdio>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int n,m;
int dp[101][101];
int a1[101]; int a2[101];

int main()
{
	int c;
	for(scanf("%d",&c);c--){
		scanf("%d %d",&n,&m);
		for(int i = 0; i < n; ++i) scanf("%d",a1+i);
		for(int j = 0; j < m; ++j) scanf("%d",a2+j);

		for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = -1;

		for()
	}
}