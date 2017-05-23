#include <iostream>
#include <cstring>

using namespace std;

int n, l;
bool point[1005];
int dp[1005][1005];

int f(int left, int right)
{
    int &ret = dp[left][right];
    if(ret != -1) return ret;

    bool flag = false;
    ret = 1e9;
    for(int i = left; i <= right; ++i)
    {
        if(point[i]) {
            ret = min(ret, f(left, i) + f(i, right) + right - left);
            flag = true;
        }
    }
    if(!flag) return 0;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    while(1)
    {
        cin >> l;
        if(l == 0) break;
        for(int i = 0; i <= l; ++i) point[i] = false;
        memset(dp, -1, sizeof(dp));

        cin >> n;
        for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            point[a] = true; 
        }

        printf("The minimum cutting is %d.\n",f(0, l));
    }
}