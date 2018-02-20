#include <cstdio>

int a, b;
bool isPrime[1000005];

void sieve(int n)
{
	for(int i = 0; i <= n; ++i) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i <= n; ++i){
		if(isPrime[i]){
			for(int j = i*2; j <= n; j+=i) isPrime[j] = false;
		}
	}
}

int main()
{
	scanf("%d %d",&a,&b);
	sieve(b);
	for(int i = a; i <= b; ++i){
		if(isPrime[i]) printf("%d\n",i);
	}
}