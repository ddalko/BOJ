#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAXV = 20000;

typedef pair<int,int> pii;

int v, e;
int src;
int dist[MAXV+5];
pii T[MAXV*4+5];
vector<int> g[MAXV+5];
vector<int> w[MAXV+5];

void build(int root, int l, int r)
{
    if(l == r){
        T[root] = pii(INF, l);
        return ;
    }
    int m = (l + r) / 2;
    build(root<<1, l, m);
    build(root<<1|1, m+1, r);
    T[root] = min(T[root<<1], T[root<<1|1]);
}

pii query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return pii(INF, INF);
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return min(query(ql, qr, root<<1, l, m), query(ql, qr, root<<1|1, m+1, r));
}

void update(int pos, int val, int root, int l, int r)
{
    if(l == r){
        T[root] = pii(val, pos);
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, root<<1, l, m);
    else update(pos, val, root<<1|1, m+1, r);
    T[root] = min(T[root<<1], T[root<<1|1]);
}

int main()
{
    scanf("%d %d",&v,&e);
    scanf("%d",&src);
    for(int i = 0; i < e; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(b);
        w[a].push_back(c);
    }

    build(1, 1, v);
    for(int i = 0; i <= v; ++i) dist[i] = INF;
    dist[src] = 0;
    update(src, 0, 1, 1, v);

    while(1)
    {
        pii cur = query(1, v, 1, 1, v);
        if(cur.first == INF) break;
        update(cur.second, INF, 1, 1, v);

        for(int i = 0; i < (int)g[cur.second].size(); ++i){
            int nxt = g[cur.second][i];
            int cost = w[cur.second][i];
            
            if(dist[nxt] > cur.first + cost){
                dist[nxt] = cur.first + cost;
                update(nxt, dist[nxt], 1, 1, v);
            }
        }        
    }

    for(int i = 1; i <= v; ++i) (dist[i] != INF) ? printf("%d\n",dist[i]) : puts("INF");
}