#include <bits/stdc++.h>

using namespace std;

int n, V, e, src, dst;
int g[31][31];
int ticket[8];
double dp[1<<8][31];

int main()
{
    while(1)
    {
        scanf("%d %d %d %d %d",&n,&V,&e,&src,&dst);
        if(n == 0 && V == 0 && e == 0 && src == 0 && dst == 0) break;

        memset(g, 0, sizeof(g));
        memset(ticket, 0, sizeof(ticket));

        for(int i = 0; i < n; ++i) scanf("%d", ticket+i);
        for(int i = 0; i < e; ++i){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            g[a-1][b-1] = c;
            g[b-1][a-1] = c;
        }

        for(int i = 0; i < (1<<n); ++i) for(int j = 0; j <= V; ++j) dp[i][j] = (double)1e9;

        double ans = (double)1e9;
        dp[0][src-1] = 0;

        for(int S = 0; S < (1<<n); ++S){
            ans = min(ans, dp[S][dst-1]);

            for(int u = 0; u < V; ++u){
                for(int i = 0; i < n; ++i){        
                    if(!(S & 1<<i)){
                        for(int v = 0; v < V; ++v){
                            if(g[u][v]){
                                double C = (double)g[u][v] / ticket[i];
                                dp[S | 1<<i][v] = min(dp[S | 1<<i][v], dp[S][u] + C);
                            }
                        }
                    }
                }
            }
        }

        if(fabs(ans - 1e9) < 0.0001) puts("Impossible");
        else printf("%f\n",ans);
    }
}