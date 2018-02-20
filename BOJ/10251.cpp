#include <cstdio>
#include <cstring>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

const int INF = 1e9;

int m, n, l, g;
int row[105][105];
int col[105][105];
int dp[105][105][205][2];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d %d",&m,&n,&l,&g);		
		int maxK = max(n, m) * 2;
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));		

		for(int i = 0; i < m; ++i) for(int j = 0; j < n-1; ++j)	scanf("%d",&row[i][j]);
		
		for(int i = 0; i < m-1; ++i) for(int j = 0; j < n; ++j)	scanf("%d",&col[i][j]);
		
		//baseCase
		for(int i = 0; i <= m; ++i) for(int j = 0; j <= n; ++j) for(int k = 0; k <= maxK; ++k) dp[i][j][k][0] = dp[i][j][k][1] = INF;
		dp[0][0][0][0] = dp[0][0][0][1] = 0;

		for(int k = 0; k < maxK; ++k){
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					dp[i+1][j][k][0] = min(dp[i+1][j][k][0], dp[i][j][k][0] + col[i][j]);
					dp[i+1][j][k+1][0] = min(dp[i+1][j][k+1][0], dp[i][j][k][1] + col[i][j]);
					dp[i][j+1][k][1] = min(dp[i][j+1][k][1], dp[i][j][k][1] + row[i][j]);
					dp[i][j+1][k+1][1] = min(dp[i][j+1][k+1][1], dp[i][j][k][0] + row[i][j]);
				}
			}	
		}

		int ans = -1;
		for(int k = 1; k <= maxK; ++k){
			if(min(dp[m-1][n-1][k][0], dp[m-1][n-1][k][1]) <= g){
				ans = k + (m + n - 2) * l;
				break;
			}
		}
		printf("%d\n",ans);
	}
}