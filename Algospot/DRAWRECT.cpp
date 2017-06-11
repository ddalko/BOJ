#include <cstdio>

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        int x[3];
        int y[3];
        for(int i = 0; i < 3; ++i) scanf("%d %d",x+i,y+i);
        printf("%d %d\n",x[0] ^ x[1] ^ x[2],y[0] ^ y[1] ^ y[2]);
    }
}