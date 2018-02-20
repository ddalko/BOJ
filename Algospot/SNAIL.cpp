#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000;

int n, m;
double dp[MAXN][MAXN*2+1];

double climb(int days, int climbed)
{
	if(days == m) return (climbed >= n) ? 1 : 0;

	double &ret = dp[days][climbed];
	if(ret + 1 - 1e-9 > 0) return ret;
	return ret = climb(days+1, climbed+1)*0.25 + climb(days+1, climbed+2)*0.75;
}

int main()
{
	int c;
	for(scanf("%d",&c);c--;){
		scanf("%d %d",&n,&m);

		for(int i = 0; i < 1000; ++i) for(int j = 0; j < 2001; ++j) dp[i][j] = -1.0;

		printf("%.10f\n", climb(0, 0));
	}
}