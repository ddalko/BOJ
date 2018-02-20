#include <bits/stdc++.h>
using namespace std;

int g[105][105];

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            g[i][j] = 1e9;
        }
    }
    for(int i = 0; i < n; ++i) g[i][i] = 0;

    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1][b-1] = min(g[a-1][b-1], c);
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d ",g[i][j]);
        }
        puts("");
    }
}