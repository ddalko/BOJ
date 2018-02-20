#include <cstdio>

char inp[22];

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0) return false;
	}
	return true;
}

int main()
{
	scanf("%s",inp);

	int sum = 0;
	for(int i = 0; inp[i]; i++) {
		if(inp[i] >= 'a') sum += inp[i]-'a'+1;
		else sum += inp[i]-'A'+1;
	}
	if(isPrime(sum)) puts("It is a prime word.");
	else puts("It is not a prime word.");
}