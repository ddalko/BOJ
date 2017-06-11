#include <cstdio>

int l[4];
int s[4];
int r[4];
int p[4];

int main()
{
    for(int i = 0; i < 4; ++i){
        scanf("%d %d %d %d",l+i,s+i,r+i,p+i);
    }

    for(int i = 0; i < 4; ++i){
        if((l[i] || s[i] || r[i]) & p[i]) {
            puts("YES");
            return 0;
        }
        if(l[i] & p[(i+3)%4]) {
            puts("YES");
            return 0;
        }
        if(s[i] & p[(i+2)%4]){
            puts("YES");
            return 0;
        }
        if(r[i] & p[(i+1)%4]){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
