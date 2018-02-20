#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long rSum[10005];
long long cSum[10000005];

int main()
{
    int x, y, m, b;
    cin >> m >> b;

    long long ans = 0;

    x = 0;
    y = b;

    for(int i = 1; i <= y + 2; ++i) rSum[i] = ((long long) i * (i + 1)) / 2;
    for(int i = 1; i <= (m * b) + 2; ++i) cSum[i] = ((long long) i * (i + 1)) / 2;

    while(1)
    {
        if(y < 0) break;

        if(x % m == 0) {
            long long banana = rSum[y] * (x+1) + cSum[x] * (y+1);
            ans = max(ans, banana);
        }      

        x++;
        y = b - (x / m);
    }
    cout << ans << '\n';    
}