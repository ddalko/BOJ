#include <cstdio>
#include <cmath>

const int MAXN = 100000;

int prime[MAXN];
bool is_prime[MAXN+1];

int sieve(int _n)
{
	int n = sqrt(_n);
	int idx = 0;
	for(int i = 0; i <= n; ++i) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i <= n; ++i){
		if(is_prime[i]){
			prime[idx++] = i;
			for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
		}
	}
	return idx;
}

int main()
{
	int N;
	scanf("%d",&N);
	int p = sieve(N);

	for(int i = 0; i < p; ++i){
		if(prime[i] >= N){
			printf("%d\n",N-1);
			return 0;
		}
		if(N % prime[i] == 0){
			printf("%d\n",N - (N/prime[i]));
			return 0;
		}
	}
	printf("%d\n",N-1);
}