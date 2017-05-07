#include <cstdio>

int n;
char ab[5] = "aabb";

int main()
{    
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        printf("%c",ab[i%4]);
    }
}