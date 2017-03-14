#include <cstdio>

#define MAX(a,b) (((a)>(b))?(a):(b))

const int MAXN = 1000;

int n;
int arr[MAXN+1];
int dp1[MAXN+1];
int dp2[MAXN+1];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",arr+i);

	for(int i=0;i<n;++i){
		dp1[i]=1;
		for(int j = 0; j < i; ++j){
			if(arr[i] > arr[j]) dp1[i] = MAX(dp1[i], dp1[j] + 1);
		}
	}

	for(int i = n-1; i >= 0; --i){
		dp2[i] = 1;
		for(int j = n-1; j > i; --j){
			if(arr[i] > arr[j]) dp2[i] = MAX(dp2[i], dp2[j] + 1);
		}
	}

	int ans = -1e9;
	for(int i = 0; i < n; ++i){
		ans = MAX(ans, dp1[i]+dp2[i]-1);
	}
	printf("%d\n",ans);
}