#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);

    int ans = n; int tmp;
    while(ans){
        bool chk = true;

        for(tmp = ans; tmp; tmp /= 10){
            if(tmp % 10 == 4 || tmp % 10 == 7) continue;
            else {
                chk = false;
                break;
            }
        }

        if(chk) {
            printf("%d\n",ans);
            break;
        }
        ans--;
    }
}