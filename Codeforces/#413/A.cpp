#include <iostream>

using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    if(k >= n) {
        puts("NO");
    }else{
        int onetime = 0;
        int tmp = n;
        while(0 < tmp){
            tmp -= k;
            onetime += t;
        }

        int ttime = 0;
        int t1 = d; int t2 = 0;
        tmp = n;

        while(t2 < d){
            t2 += t;
            tmp -= k;
        }

        int idx = 0;
        while(tmp > 0){
            if(idx%2){
                t2 += t;
                tmp -= k;
            }else{
                t1 += t;
                tmp -= k;
            }
            idx++;
        }
        ttime = max(t1, t2);
        if(ttime < onetime) puts("YES");
        else puts("NO");
    }
}