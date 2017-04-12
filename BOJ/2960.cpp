#include <cstdio>
#include <cmath>

const int MAXN = 1001;

int n, k;

bool is_prime[MAXN];

void sieve(int n)
{
	int idx = 0;
	int cnt = 0;

	for(int i = 0; i <= n; ++i) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i <= n; ++i){
		if(is_prime[i]){
			cnt++;
			if(cnt == k){
				printf("%d\n",i);
				return ;
			}
			for(int j = 2 * i; j <= n; j += i) {
				if(is_prime[j]) cnt++;
				is_prime[j] = false;
				
				if(cnt == k){
					printf("%d\n",j);
					return ;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	sieve(n);
}