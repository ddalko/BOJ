#include <cstdio>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int v, e;
int g[405][405];

int main()
{
    scanf("%d %d",&v,&e);
    for(int i = 0; i < v; ++i) for(int j = 0; j < v; ++j) g[i][j] = 1e9;

    for(int i = 0; i < e; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1][b-1] = c;
    }

    for(int k = 0; k < v; ++k){
        for(int i = 0; i < v; ++i){
            for(int j = 0; j < v; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    
    int ans = 1e9;
    for(int i = 0; i < v; ++i){
        ans = min(ans, g[i][i]);
    }
    if(ans != 1e9) printf("%d\n",ans);
    else puts("-1");
}