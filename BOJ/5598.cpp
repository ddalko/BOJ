#include <cstdio>

int main()
{
	char inp[1005];
	scanf("%s",inp);

	for(int i = 0; inp[i]; ++i) putchar((inp[i]-42)%26+65);
}