#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
int inp[5005];
int dp[5005][5005];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d", inp+i);
	for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) dp[i][j] = INF;

	for(int i = n-1; i >= 0; --i){
		for(int j = i; j < n; ++j){
			if(i == j) {
				dp[i][j] = 0;
			}else if(i+1 == j && inp[i] == inp[j]) {
				dp[i][j] = 0;
			}else {
				if(inp[i] == inp[j]) {
					dp[i][j] = dp[i+1][j-1];
				}
				dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j-1]) + 1);
			}
		}
	}
	printf("%d\n", dp[0][n-1]);
}