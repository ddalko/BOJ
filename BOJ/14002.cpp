#include <cstdio>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int n;
int arr[1001];
int dp[1001];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d",arr+i);

	int m = -1e9;
	for(int i = 0; i < n; ++i){
		dp[i] = 1;
		for(int j = 0; j <= i; ++j){
			if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
		}
		m = max(m, dp[i]);
	}
	printf("%d\n", m);

	int tmp = 1e9;
	for(int i = n-1; i >= 0; --i){
		if(dp[i] == m && arr[i] < tmp) {
			dp[i] = -1;
			m--;
		}
	}
	for(int i = 0; i < n; ++i) if(dp[i]==-1) printf("%d ", arr[i]);
	printf("\n");
}