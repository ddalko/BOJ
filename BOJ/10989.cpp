#include <cstdio>

int n;
int arr[10001];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		arr[a]++;
	}

	for(int i = 0; i < 10001; ++i){
		while(arr[i]--) printf("%d\n",i);
	}
}