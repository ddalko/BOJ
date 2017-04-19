#include <cstdio>

int n;
char a[13] = "ABCDEFGHIJKL";
char b[11] = "0123456789";

int main()
{
    scanf("%d",&n);
    n += 56;
    n %= 60;
    printf("%c%c\n",a[n%12],b[n%10]);
}