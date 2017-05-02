#include <cstdio>

int n;
int a[4], b[4], c[4];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int x, y, z;
        scanf("%d %d %d",&x,&y,&z);
        a[0] += x; a[x]++;
        b[0] += y; b[y]++;
        c[0] += z; c[z]++;
    }

    if(a[0] > b[0]){
        if(a[0] > c[0]){
            printf("1 %d\n",a[o]);
        }else if(a[0] == c[0]){
            if(a[1] == c[1]){

            }else
        }
    }else if(a[0] == b[0]){

    }else{

    }
}