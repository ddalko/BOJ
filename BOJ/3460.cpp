#include <cstdio>

int main()
{
    int t, n;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        
        for(int i = 0; i < 21; ++i){
            if(n & 1<<i) printf("%d ",i);
        }
    }
}