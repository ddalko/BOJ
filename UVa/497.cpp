#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
string temp;
int arr[10005];
int idx[10005];
int dp[10005];

int main()
{
    int t;
    cin >> t;
    getline(cin, temp);
    getline(cin, temp);

    while(t--){

        n = 0;
        while(1){
            getline(cin, temp);
            if(cin.eof()) break;
            if(temp.compare("#") == 0) break;
            arr[n++] = atoi(temp.c_str());
        }
        for(int i = 0; i <= n; ++i) printf("%d ",arr[i]);
        for(int i = 0; i <= n; ++i) dp[i] = 0;

        int ans = -1e9;
        int maxIdx = 0;
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(arr[i] > arr[j]){
                    if(dp[i] > dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        arr[i] = j;
                    }
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
                maxIdx = i;
            }
        }

        vector<int> a;
        for(int k = maxIdx; k >= 0; k = idx[k]){
            a.push_back(k);
        }

        printf("%d\n",ans);
    }
}