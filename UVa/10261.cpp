#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ar[201][10001];

void pr(int i, int &j)
{
    if(i == 0) return ;
    pr(i - 1, ar[i][j]);
    cout << ((j == ar[i][j]) ? "port" : "starboard") << '\n';
}

int main()
{
    int length;
    int t, i, j, x, y;
    cin >> t;
    while(t--){
        cin >> length;
        length *= 100;
        memset(ar, -1, sizeof(ar));

        ar[0][0] = 0;
        y = 0;

        for(i = 0; i < 200; ++i){
            cin >> x;
            if(!x) break;
            y += x;
            bool flag = false;

            for(j = 0; j < 10001; ++j){
                if(ar[i][j] >= 0){
                    if(j + x <= length && y - x - j <= length){
                        ar[i+1][j+x] = j;
                        flag = true;
                    }
                    
                    if(j <= length && y - j <= length){
                        ar[i+1][j] = j;
                        flag = true;
                    }
                }   
            }
            if(!flag) break;
        }
        while(x) cin >> x;

        cout << i << '\n';
        for(j = 0; j < 10001 && ar[i][j] < 0; ++j);

        pr(i, j);

        if(t > 0) cout << '\n';
    }
    return 0;
}