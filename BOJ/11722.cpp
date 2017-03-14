#include <cstdio>

#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
{
	int n;
	int arr[1001];
	int dp[1001];

	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",arr+i);

	int ans=-1e9;
	for(int i=0;i<n;++i){
		dp[i]=1;
		for(int j=0;j<=i;++j){
			if(arr[j]>arr[i]) dp[i]=MAX(dp[i],dp[j]+1);
		}
		ans=MAX(dp[i],ans);
	}
	printf("%d\n",ans);
}