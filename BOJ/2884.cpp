#include <cstdio>

int main()
{
    int h, m;
    scanf("%d %d",&h,&m);
    
    h = (m - 45 < 0) ? (h - 1 + 24) % 24 : h;
    m = (m + 60 - 45) % 60;
    
    printf("%d %d", h, m);
}