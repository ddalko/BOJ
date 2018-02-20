#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 10000000;

int dp[105][105];

int f(int n, int first)
{
	if(n == first) return 1;

	int &ret = dp[n][first];
	if(ret != -1) return ret;

	ret = 0;
	for(int second = 1; second <= n-first; ++second){
		int add = first + second - 1;
		add *= f(n-first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main()
{
	int c;
	for(scanf("%d",&c);c--;){
		memset(dp, -1, sizeof(dp));
		int r;
		scanf("%d",&r);
		int ans = 0;
		for(int i = 1; i <= r; ++i) {
			ans += f(r, i);
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
}