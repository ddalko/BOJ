#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m, k;
priority_queue<int> dist[1005];
vector<pii> g[1005];

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    dist[src].push(0);
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(int i = 0; i < (int)g[cur].size(); ++i){
            int nxt = g[cur][i].first;
            int nxtCost = g[cur][i].second + cost;

            if(dist[nxt].size() < k) {
                dist[nxt].push(nxtCost);
                pq.push(make_pair(nxtCost, nxt));
            }else if(dist[nxt].top() > nxtCost) {
                dist[nxt].pop();
                dist[nxt].push(nxtCost);
                pq.push(make_pair(nxtCost, nxt));
            }            
        }
    }

    for(int i = 1; i <= n; ++i) printf("%d\n", dist[i].size() == k ? dist[i].top() : -1);
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(make_pair(b, c));
    }    
    dijkstra(1);
}