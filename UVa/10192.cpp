#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char inp1[105];
char inp2[105];
int dp[105][105];

int main()
{
    int Case = 1;
    while(cin.getline(inp1, 105)){
        if(inp1[0] == '#') return 0;
        
        cin.getline(inp2, 105);

        int l1 = strlen(inp1);
        int l2 = strlen(inp2);

        for(int i = 0; i <= l1; ++i) for(int j = 0; j <= l2; ++j) dp[i][j] = 0;

        for(int i = 1; i <= l1; ++i){
            for(int j = 1; j <= l2; ++j){
                if(inp1[i-1] == inp2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        printf("Case #%d: you can visit at most %d cities.\n", Case++, min(dp[l1][l2], 63));
    }
}