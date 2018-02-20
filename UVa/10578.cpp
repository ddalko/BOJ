#include <bits/stdc++.h>

using namespace std;

int state[6];
int dp[5][5][5][5][5][5][32];

void f()
{
    for(int d1 = 0; d1 < 5; ++d1) {
        for(int d2 = 0; d2 < 5; ++d2) {
            for(int d3 = 0; d3 < 5; ++d3) {
                for(int d4 = 0; d4 < 5; ++d4) {
                    for(int d5 = 0; d5 < 5; ++d5) {
                        for(int d6 = 0; d6 < 5; ++d6) {
                            dp[d1][d2][d3][d4][d5][d6][31] = 1;
                        }
                    }
                }
            }
        }
    }
              
    for(int i = 30; i >= 0; --i){
        for(int d1 = 0; d1 < 5; ++d1){
            for(int d2 = 0; d2 < 5; ++d2){
                for(int d3 = 0; d3 < 5; ++d3){
                    for(int d4 = 0; d4 < 5; ++d4){
                        for(int d5 = 0; d5 < 5; ++d5){
                            for(int d6 = 0; d6 < 5; ++d6){
                                bool f1 = (i+1 > 31 || !d1 || dp[d1-1][d2][d3][d4][d5][d6][i+1] == 2);
                                bool f2 = (i+2 > 31 || !d2 || dp[d1][d2-1][d3][d4][d5][d6][i+2] == 2);
                                bool f3 = (i+3 > 31 || !d3 || dp[d1][d2][d3-1][d4][d5][d6][i+3] == 2);
                                bool f4 = (i+4 > 31 || !d4 || dp[d1][d2][d3][d4-1][d5][d6][i+4] == 2);
                                bool f5 = (i+5 > 31 || !d5 || dp[d1][d2][d3][d4][d5-1][d6][i+5] == 2);
                                bool f6 = (i+6 > 31 || !d6 || dp[d1][d2][d3][d4][d5][d6-1][i+6] == 2);

                                if(f1 && f2 && f3 && f4 && f5 && f6) dp[d1][d2][d3][d4][d5][d6][i] = 1;
                                else dp[d1][d2][d3][d4][d5][d6][i] = 2;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    f();

    string inp;
    while(cin >> inp)
    {
        int sum = 0;
        for(int i = 0; i < 6; ++i) state[i] = 4;        
        for(int i = 0; i < inp.size(); ++i) {
            state[inp[i]-'1']--;
            sum += inp[i]-'0';
        }

        int ans = dp[state[0]][state[1]][state[2]][state[3]][state[4]][state[5]][sum];
        cout << inp;
        if(ans == 1){
            if(inp.size() % 2) cout << " A\n";
            else cout << " B\n";
        }else if(ans == 2){
            if(inp.size() % 2) cout << " B\n";
            else cout << " A\n";
        }else cout << "draw" << '\n';
    }

    return 0;
}