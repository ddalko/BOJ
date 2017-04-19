#include <cstdio>

int n, m;
bool g[105][105];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = true;
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                g[i][j] |= (g[i][k] && g[k][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            if(i==j || g[i][j] || g[j][i]) sum++;
        }
        printf("%d\n",n - sum);
    }
}