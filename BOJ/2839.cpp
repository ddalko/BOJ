#include <cstdio>

const int INF = 1e9;

int n;
int dp[5005];

int main()
{
	scanf("%d",&n);

	dp[1] = dp[2] = dp[4] = INF;
	dp[3] = 1;
	for(int i = 5; i <= n; ++i) dp[i] = (dp[i-5] > dp[i-3]) ? dp[i-3] + 1 : dp[i-5] + 1;
	printf("%d\n",(dp[n] >= INF) ? -1 : dp[n]);
}