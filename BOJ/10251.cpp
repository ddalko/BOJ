#include <cstdio>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

const int INF = 1e9;

int n, m, l, g;
int row[105][105];
int col[105][105];
int dp[105][105][205][2];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d %d",&n,&m,&l,&g);

		int maxK = max(n, m) * 2;
		for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) row[i][j] = col[i][j] = 0;
		for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) for(int k = 0; k <= maxK; ++k) dp[i][j][k][0] = dp[i][j][k][1] = INF;

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m-1; ++j){
				scanf("%d",&row[i][j]);
			}
		}

		for(int i = 0; i < n-1; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d",&col[i][j]);
			}
		}

		dp[0][0][0][0] = dp[0][0][0][1] = 0;
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				for(int k = 0; k < maxK; ++k){
					dp[i+1][j][k][0] = min(dp[i+1][j][k][0], dp[i][j][k][0] + col[i][j]);
					dp[i+1][j][k+1][0] = min(dp[i+1][j][k+1][0], dp[i][j][k][1] + col[i][j]);
					dp[i][j+1][k][1] = min(dp[i][j+1][k][1], dp[i][j][k][1] + row[i][j]);
					dp[i][j+1][k+1][1] = min(dp[i][j+1][k+1][1], dp[i][j][k][0] + row[i][j]);
				}
			}
		}

		int ans = -1;
		for(int k = 1; k <= maxK; ++k){
			if(min(dp[n-1][m-1][k][0], dp[n-1][m-1][k][1]) <= g){
				ans = k + (n + m - 2) * l;
				break;
			}
		}
		printf("%d\n", ans);
	}
}