#include <cstdio>

using namespace std;

int main()
{
    int hh; 
    int mm;
    scanf("%d:%d",&hh,&mm);

    int ans = 0;
    while(1) {
        if((int)(hh / 10) == mm % 10 && (int)(mm / 10) == hh % 10) break;
        mm++;
        ans++;
        if(mm > 59){
            mm = 0;
            hh = ++hh % 24;
        }
    }
    printf("%d\n",ans);
}