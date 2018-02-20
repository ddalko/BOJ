#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

int n;
int arr[MAXN+1];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d",arr+i);
	sort(arr, arr+n);

	int ans = n;
	for(int i = 0; i < n; ++i){
		ans = min(ans, arr[i] + n - i - 1);
	}

	printf("%d\n",ans);
}