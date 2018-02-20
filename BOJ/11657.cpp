#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair
#define eb emplace_back
typedef pair<int,int> pii;

int n, m;
int dist[505];
vector<pii> g[505];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].eb(mp(b,c));
    }

    bool updated;
    for(int i = 0; i <= n; ++i) dist[i] = 1e9;
    
    dist[1] = 0;
    for(int iter = 1; iter <= n; ++iter){
        updated = false;
        for(int v = 1; v <= n ; ++v){
            for(int e = 0; e < (int)g[v].size(); ++e){
                int there = g[v][e].first;
                int cost = g[v][e].second;
                if(dist[there] > dist[v] + cost){
                    dist[there] = dist[v] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }

    int M = 500 * 10000;
    if(updated) {
        puts("-1");
        return 0;
    }else{
        for(int i = 2; i <= n; ++i){
            if(dist[i] < 1e9 - M) printf("%d\n",dist[i]);
            else puts("-1");
        }
    }
}