#include <cstdio>

int N;

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0) return false;
	}
	return n != 1;
}

bool isPalin(int n)
{
	int tmp = n;
	int cmp = 0;
	while(tmp){
		cmp *= 10;
		cmp += tmp % 10;
		tmp /= 10;
	}
	return (n == cmp);
}

int main()
{
	scanf("%d",&N);
	while(1)
	{
		if(isPalin(N) && isPrime(N)){
			printf("%d\n",N);
			break;
		}
		N++;
	}
}