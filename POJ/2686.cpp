#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct state{
    int used;
    double w;
    int cur;

    state(int _used, double _w, int _cur){
        used = _used;
        w = _w;
        cur = _cur;
    }
};

typedef pair<int,int> pii;

int v, n, e, src, dst;
int ticket[8];
bool in_q[32][1<<8];
double dist[32][1<<8];
vector<pii> g[32];

double dijkstra(int src)
{
    queue<state> q;
    for(int i = 0; i <= v; ++i) {
        for(int j = 0; j < (1<<n); ++j){
            in_q[i][j] = false;
            dist[i][j] = (double)1e9;
        }
    }

    dist[src][0] = 0;
    state first(0, 0, src);
    q.push(first);
    in_q[src][0] = true;
    
    while(!q.empty()){
        int curNode = q.front().cur;
        int curUsed = q.front().used;
        q.pop();
        in_q[curNode][curUsed] = false;

        for(int i = 0; i < (int)g[curNode].size(); ++i){
            int nxtNode = g[curNode][i].first;

            for(int j = 0; j < n; ++j){
                if(!(curUsed & (1<<j))){
                    int nxtUsed = curUsed | (1<<j);
                    double nxtCost = (double)g[curNode][i].second / ticket[j];

                    if(dist[nxtNode][nxtUsed] > dist[curNode][curUsed] + nxtCost){
                        dist[nxtNode][nxtUsed] = dist[curNode][curUsed] + nxtCost;
                        
                        if(!in_q[nxtNode][nxtUsed]){
                            state nxtState(nxtUsed, dist[curNode][curUsed] + nxtCost, nxtNode);
                            q.push(nxtState);
                            in_q[nxtNode][nxtUsed] = true;
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
        scanf("%d %d %d %d %d",&n,&v,&e,&src,&dst);
        if(n == 0 && v == 0 && e == 0 && src == 0 && dst == 0) break;
        for(int i = 0; i <= v; ++i) g[i].clear();

        for(int i = 0; i < n; ++i) scanf("%d",ticket+i);
        for(int i = 0; i < e; ++i){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(make_pair(b, c));
            g[b].push_back(make_pair(a, c));
        }

        double ans = dijkstra(src);
        if(fabs(ans - 1e9) < 0.000001) puts("Impossible");
        else printf("%f\n",ans);
    }
}