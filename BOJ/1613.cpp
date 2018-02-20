#include <cstdio>

int n, k;
bool g[405][405];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 0; i < k; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = true;
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                g[i][j] |= (g[i][k] & g[k][j]);
            }
        }
    }
    
    int s;
    for(scanf("%d",&s);s--;){
        int x, y;
        scanf("%d %d",&x,&y);
        if(g[x-1][y-1]) puts("-1");
        else if(g[y-1][x-1]) puts("1");
        else puts("0");        
    }    
}