#include <cstdio>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, m;
int g[105][105];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) g[i][j] = 1e9;
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = g[b-1][a-1] = 1;
    }

    for(int k = 0; k < n; ++k){

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = -1; int M = 1e9;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j) if(j != i) sum += g[i][j];
        if(sum < M) {
            ans = i+1;
            M = sum;
        }
    }
    printf("%d\n",ans);
}