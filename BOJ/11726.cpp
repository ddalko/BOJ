#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);

	int a=0,b=1,c;
	for(int i=0;i<n;++i){
		c=(a+b)%10007;
		a=b;
		b=c;
	}
	printf("%d\n",c);
}