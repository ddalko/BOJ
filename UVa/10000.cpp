#include <cstdio>
#include <algorithm>

using namespace std;

int n, s;
int g[101][101];

int main()
{
    int t = 0, a, b;
    while(scanf("%d",&n), n != 0){
        for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) g[i][j] = 0;
        scanf("%d",&s);
        while(scanf("%d %d",&a,&b), a != 0 && b != 0) g[a][b] = 1;

        for(int k = 1; k <= n; ++k){
            if(k == s) continue;
            for(int i = 1; i <= n; ++i){
                if(i == k) continue;
                for(int j = 1; j <= n; ++j){
                    if(j == s) continue;
                    if(j == k || i == j) continue;
                    if(!g[i][k] || !g[k][j]) continue;
                    
                    g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        
        int ans = 0; int ansIdx = 0;
        for(int i = 1; i <= n; ++i){
            if(g[s][i] > ans && s != i){
                ans = g[s][i];
                ansIdx = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",++t, s, ans, ansIdx);
        puts("");
    }
}