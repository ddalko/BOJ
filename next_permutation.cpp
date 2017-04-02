#include <cstdio>
#include <algorithm>

int n;
int arr[10];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d",arr+i);

	do{
		for(int i = 0; i < n; ++i) printf("%d ",arr[i]);
		printf("\n");
	}while(std::next_permutation(arr, arr+n));
}