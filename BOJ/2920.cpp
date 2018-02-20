#include <cstdio>

int a, x;

int main()
{
    int ans;
    scanf("%d",&a);
    for(int i = 1; i < 7; ++i){
        scanf("%d",&x);
        if( x - a == 1 && ans != 3) ans = 1;
        else if( x - a == -1 && ans != 3) ans = 2;
        else ans = 3;
        a = x;
    }
    
    if(ans == 1) puts("ascending");
    else if(ans == 2) puts("descending");
    else if(ans == 3) puts("mixed");
}