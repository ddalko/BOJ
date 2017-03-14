#include <cstdio>

#define MIN(a,b) (((a)<(b))?(a):(b))

int x;
int dp[1000002];

int main()
{
	scanf("%d",&x);

	for(int i=2;i<=x;++i) dp[i]=1e9;
	for(int i=1;i<=x;++i){
		if(i*3<=x) dp[i*3] = MIN(dp[i*3],dp[i]+1);
		if(i*2<=x) dp[i*2] = MIN(dp[i*2],dp[i]+1);
		if(i+1<=x) dp[i+1] = MIN(dp[i+1],dp[i]+1);
	}
	printf("%d\n",dp[x]);
}