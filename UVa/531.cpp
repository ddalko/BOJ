#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a[101];
string b[101];
pair<int, int> dp[105][105];

void path(int an, int bn)
{
    if(dp[an][bn].second == 2) path(an - 1, bn);
    if(dp[an][bn].second == 3) path(an, bn - 1);
    if(dp[an][bn].second == 1) {
        if(dp[an][bn].first == 1){
            cout << a[an];
        }else {
            path(an - 1, bn - 1);
            cout << " " << a[an];
        }
    }
}

int main()
{
    while(!cin.eof())
    {
        int an = 1;
        cin >> a[an];
        if(cin.eof()) break;

        do{
            cin >> a[++an];
        }while(a[an][0] != '#');

        int bn = 0;
        do{
            cin >> b[++bn];
        }while(b[bn][0] != '#');

        for(int i = 0; i <= an; ++i) for(int j = 0; j <= bn; ++j) dp[i][j].first = dp[i][j].second = 0;
        --an;
        --bn;

        for(int i = 1; i <= an; ++i){
            for(int j = 1; j <= bn; ++j){
                if(a[i] == b[j]){
                    dp[i][j].first = dp[i-1][j-1].first + 1;
                    dp[i][j].second = 1;
                }
                else if(dp[i-1][j].first > dp[i][j-1].first){
                    dp[i][j].first = dp[i-1][j].first;
                    dp[i][j].second = 2;
                }else{
                    dp[i][j].first = dp[i][j-1].first;
                    dp[i][j].second = 3;
                }
            }
        }

        path(an, bn);
        cout << '\n';
    }
}