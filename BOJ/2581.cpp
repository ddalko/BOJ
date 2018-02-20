#include <cstdio>
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int a, b;
bool isPrime[10005];

void sieve(int n)
{
	for(int i = 0; i <= n; ++i) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;

	for(int i = 0; i <= n; ++i){
		if(isPrime[i]){
			for(int j = i*2; j <= n; j+=i) isPrime[j] = false;
		}
	}
}

int main()
{
	scanf("%d %d",&a,&b);
	sieve(b);
	int min = 1e9; int sum = 0;
	for(int i = a; i <= b; ++i){
		if(isPrime[i]){
			sum += i;
			min = MIN(min, i);
		}
	}
	if(sum != 0) printf("%d\n%d\n",sum,min);
	else puts("-1");
}