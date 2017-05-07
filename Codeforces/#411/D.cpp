#include <string>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;
string inp;

int main()
{
    cin >> inp;
    int len = inp.size();
    long long ans = 0;
    for(int i = len-1; i >= 0; --i){
        long long p = 0;
        if(inp[i] == 'b' && i != 0){
            i--;
            int cnt = 0;
            while(inp[i--] =='a') cnt++;
            if(cnt == 1) p = 1;
            else if(cnt == 2) p = 3;
            else {
                long long pow = 2;
                for(int j = 0; j < cnt-1; ++j) pow  = (pow * 2) % MOD;
                p = pow-1;
            }
        }
        ans += p % MOD;
    }   
    cout << ans << endl;
}