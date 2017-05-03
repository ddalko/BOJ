#include <cstdio>
#include <algorithm>

using namespace std;

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int n, m;
char C[15][15];
int dp[15][15][2];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; ++i) scanf("%s",C[i]);

        if(C[0][0] == '.') dp[0][0] 
    }
}