#include <cstdio>

int mod=1e9;
int dp[2][11];

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=2;i<11;++i) dp[0][i]=1;

	for(int i=1;i<n;++i) {
		for(int j=1;j<11;++j){
			dp[i%2][j]=(dp[(i+1)%2][j-1]+dp[(i+1)%2][j+1])%mod;
		}
	}
	long long ans=0;
	for(int i=1;i<11;++i) ans+=dp[(n+1)%2][i];
	printf("%lld\n",ans%mod);
}