#include <cstdio>

int main()
{
	int n;
	int a, b, c;
	scanf("%d",&n);

	a = 0; b = 1; c = 1;
	for(int i = 1; i < n; ++i){
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d\n",c);
}