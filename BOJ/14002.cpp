#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int dp[1005];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d", a+i);

	int ans = -1e9;
	for(int i = 0; i < n; ++i){
		dp[i] = 1;
		for(int j = 0; j <= i; ++j){
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);

	int tmp = 1e9;
	for(int i = n-1; i >= 0; --i){
		if(dp[i] == ans && a[i] < tmp) {
			dp[i] = -1;
			ans--;
		}
	}
	for(int i = 0; i < n; ++i) if(dp[i]==-1) printf("%d ", a[i]);
	printf("\n");

}