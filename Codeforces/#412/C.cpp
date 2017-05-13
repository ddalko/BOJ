#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        
        if(p == 0){
            cout << (x == 0 ? 0 : -1) << '\n';
            continue;
        }

        if(p == q){
            cout << (x == y ? 0 : -1) << '\n';
            continue;
        }

        int t1 = (x + p - 1) / p;
        int t2 = ((y - x) + (q - p) - 1) / (q - p);
        cout << (q * 1LL * max(t1, t2) - y) << '\n';
    }
}