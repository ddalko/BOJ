#include <cstdio>

int gcd(int u, int v)
{
    return (v == 0) ? u : gcd(v, u % v);
}

int main()
{
    int a, b;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a == 0 && b == 0) break;

        int d = gcd(a, b);
        if(d == b){
            puts("multiple");
        }else if(d == a){
            puts("factor");
        }else{
            puts("neither");
        }
    }
}