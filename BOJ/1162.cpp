#include <bits/stdc++.h>

using namespace std;

struct state{
    int w;
    int v;
    int s;

    state(int _w, int _v, int _s){
        w = _w;
        v = _v;
        s = _s;
    }

    bool operator < (const state rhs) const
    {
        if(w != rhs.w) return w > rhs.w;
        if(v != rhs.v) return v < rhs.v;
        return s < rhs.s;
    }
};

typedef pair<int,int> pii;

const int INF = 1e9;

int n, m, k;
int dist[10005][21];
vector<pii> g[10005];

// void spfa() {
//     init
//     inq[init] = true;
//     q.push(init);
//     while (!q.empty()) {
//         int cur = q.front();
//         q.pop();
//         inq[cur] = false;
//         if (good) {
//             gangsin
//             if (!inq[nxt]) {
//                 inq[nxt] = true;
//                 q.push(nxt);
//             }
//         }
//     }
// }

int dijkstra(int src)
{
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= k; ++j) dist[i][j] = INF;

    priority_queue<state> pq;
    state tmp(0, 0, 0);
    pq.push(tmp);
    dist[0][0] = 0;

    while(!pq.empty()){
        int cur = pq.top().v;
        int cdist = pq.top().w;
        int packed = pq.top().s;
        pq.pop();

        if(dist[cur][packed] < cdist) continue;

        for(int i = 0; i < (int)g[cur].size(); ++i){
            int nxt = g[cur][i].first;
            int nxtCost = g[cur][i].second;
            
            if(dist[nxt][packed] > cdist + nxtCost){
                dist[nxt][packed] = cdist + nxtCost;
                state nopack(cdist + nxtCost, nxt, packed);
                pq.push(nopack);
            }
            if(packed+1 <= k && dist[nxt][packed+1] > cdist){
                dist[nxt][packed+1] = cdist;
                state pack(cdist, nxt, packed + 1);
                pq.push(pack);
            }
        }
    }
    
    int ret = 1e9;
    for(int i = 0; i <= k; ++i) ret = min(ret, dist[n-1][i]);
    return ret;
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1].push_back(make_pair(b-1, c));
        g[b-1].push_back(make_pair(a-1, c));
    }

    printf("%d\n",dijkstra(0));
}