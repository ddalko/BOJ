#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int n, v, e, src, dst;
int ticket[8];
vector<pii> g[32];
bool in_q[32][1<<8];
double dist[32][1<<8];

double dijkstra(int src)
{
    for(int i = 0; i <= v; ++i) for(int j = 0; j < (1<<n); ++j) { dist[i][j] = (double)1e9; in_q[i][j] = false; }

    queue<pii> q;
    dist[src][0] = 0;
    q.push(make_pair(src, 0));
    in_q[src][0] = true;

    while(!q.empty())
    {
        int curNode = q.front().first;
        int curState = q.front().second;
        in_q[curNode][curState] = false;
        q.pop();

        for(int i = 0; i < (int)g[curNode].size(); ++i){
            for(int j = 0; j < n; ++j){
                if(!(curState & 1<<j)){
                    int nxtNode = g[curNode][i].first;
                    int nxtState = curState | 1<<j;
                    double nxtCost = (double)g[curNode][i].second / ticket[j];
                    
                    if(dist[nxtNode][nxtState] > dist[curNode][curState] + nxtCost) {
                        dist[nxtNode][nxtState] = dist[curNode][curState] + nxtCost;
                        
                        if(!in_q[nxtNode][nxtState]){
                            q.push(make_pair(nxtNode, nxtState));
                            in_q[nxtNode][nxtState] = true;
                        }
                    }
                }
            }
        }
    }

    double ret = (double)1e9;
    for(int i = 0; i < (1<<n); ++i) ret = min(ret, dist[dst][i]);
    return ret;
}

int main()
{
    while(1)
    {
        scanf("%d %d %d %d %d",&n, &v, &e, &src, &dst);
        if(n == 0 && v == 0 && e == 0 && src == 0 && dst == 0) break;
        for(int i = 0; i <= v; ++i) g[i].clear();

        for(int i = 0; i < n; ++i) scanf("%d", ticket+i);

        for(int i = 0; i < e; ++i){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(make_pair(b, c));
            g[b].push_back(make_pair(a, c));
        }
        
        double ans = dijkstra(src);
        if(fabs(ans - 1e9) < 0.00001) puts("Impossible");
        else printf("%f\n",ans);
    }
}