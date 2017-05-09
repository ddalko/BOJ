#include <cstdio>

int p, x, y;

int main()
{
    int ans = 0;
    scanf("%d %d %d",&p,&x,&y);

/*    while(true){
        int i = (x / 50) % 475;
        
        for(int r = 0; r < 25; ++r) {
            i = (i * 96 + 42) % 475;

            if(p == i+26) {
                printf("%d\n",ans);
                return 0;
            }
        }

        if(x - 50 > y) x -= 50;
        else {
            x += 100;
            ans++;
        }
    }*/

    int X = (((p-26) % 475 - 42) / 96) % 475 * 50;
    printf("%d\n",X);
}