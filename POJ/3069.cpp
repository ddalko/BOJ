#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1002];

int main()
{
	int n, r;
	while(scanf("%d %d",&r,&n), n!=-1 && r!=-1){
		for(int i = 0; i < n; ++i) scanf("%d", arr+i);
		sort(arr, arr+n);

		int idx = 0; int ans = 0;
		while(idx < n){
			int s = arr[idx++];
			while(idx < n && s + r >= arr[idx]) idx++;
			int point = arr[idx-1];
			while(idx < n && point + r >= arr[idx]) idx++;
			ans++;
		}
		printf("%d\n",ans);
	}
}