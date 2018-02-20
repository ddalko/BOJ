#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);

	int ans = 0;
	for(int i = 1; i < n; ++i){
		int sum = i;
		int tmp = i;

		while(tmp){
			sum += (tmp % 10);
			tmp /= 10;
		}
		
		if(sum == n){
			ans = i;
			break;
		}
	}
	if(ans) printf("%d\n", ans);
	else puts("0");
}