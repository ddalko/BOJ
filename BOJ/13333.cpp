#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1001];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d", a+i);
	sort(a, a+n);

	for(int i = n; i >= 0; i--){
		if(a[n - i] >= i){
			printf("%d\n",i);
			break;
		}
	}
}