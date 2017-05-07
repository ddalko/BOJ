#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int n, a;
int dp[100005];
vector<int> arr;

int main() {
	while(cin >> n){
        arr.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d",&a);
            arr.emplace_back(a);
        }
        
        for(int i = 0; i <= n; ++i) dp[i] = 1e9;
        for(int i = 0; i < n; ++i) *lower_bound(dp, dp+n, arr[i]) = arr[i];
	    
        for (int i = 0; i <= n; i++) {
		    if (dp[i] == 1e9) {
			    printf("%d\n",i);
			    break;
		    }
	    }
    }
}