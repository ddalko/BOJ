#include <cstdio>

const int MAXN = 1000;

bool isPrime[MAXN+1];

void sieve()
{
	for(int i = 0; i <= 1000; ++i) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i <= 1000; ++i){
		if(isPrime[i]){
			for(int j = i * 2; j <= 1000; j += i){
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	int n, ans = 0;
	scanf("%d",&n);
	sieve();
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d",&a);
		if(isPrime[a]) ans++;
	}
	printf("%d\n",ans);
}