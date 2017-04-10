#include <cstdio>

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	int t = (a * 3600) + (b * 60) + c + d;
	int h = (t / 3600) % 24;
	t %= 3600;
	int m = (t / 60) % 60;
	t %= 60;
	int s = t % 60;
	printf("%d %d %d\n",h,m,s);
}