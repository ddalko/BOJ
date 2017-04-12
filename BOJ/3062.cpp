#include <cstdio>

int f(int n)
{
	int ret = 0;
	while(n){
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		int N;
		scanf("%d",&N);
		N += f(N);
		printf("%d\n",N);
		if(N == f(N)) puts("YES");
		else puts("NO");
	}
}