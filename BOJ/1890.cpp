#include <bits/stdc++.h>
using namespace std;

int n;
int board[105][105];
long long dp[105][105];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j){
			scanf("%d", &board[i][j]);
		}
	}

	dp[0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == n-1 && j == n-1) continue;
			if(dp[i][j] > 0){
				int step = board[i][j];
				if(step + i < n) dp[step+i][j] += dp[i][j];
				if(step + j < n) dp[i][step+j] += dp[i][j];
			}
		}
	}
	printf("%lld\n", dp[n-1][n-1]);
}	