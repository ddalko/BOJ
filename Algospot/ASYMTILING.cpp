#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 100;
int dp[101];

int tiling(int width)
{
	if(width <= 1) return 1;

	int &ret = dp[width];
	if(ret != -1) return ret;
	return ret = (tiling(width-1) + tiling(width-2)) % MOD;
}

int asymmetric(int width)
{
	if(width % 2) return (tiling(width) - tiling(width/2) + MOD) % MOD;

	int ret = tiling(width);
	ret = (ret - tiling(width/2) + MOD) % MOD;
	ret = (ret - tiling(width/2-1) + MOD) % MOD;
	return ret;
}

int main()
{
	int c;
	for(scanf("%d",&c);c--;){
		memset(dp, -1, sizeof(dp));
		int n;
		scanf("%d", &n);
		printf("%d\n", asymmetric(n));
	}
}