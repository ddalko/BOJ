#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
struct edge {
    int next;
    double weight;
    bool operator < (const edge& p) const {
        if(abs(weight - p.weight) < 1e-9) return next < p.next;
        return weight > p.weight;
    }
};
vector<edge> adj[10001];
double cost[10001];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; ++i){
            adj[i].clear();
            cost[i] = -1;
        }
        while(m--){
            int u, v;
            double w;
            scanf("%d %d %lf", &u, &v, &w);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
       
        priority_queue<edge> pq;
        pq.push({0, 1});
        cost[0] = 1;

        while(!pq.empty()){
            int cur = pq.top().next;
            pq.pop();
           
            if(cur == n-1) break;
           
            for(int i=0; i<adj[cur].size(); ++i){
                int next = adj[cur][i].next;
                double nextW = cost[cur] * adj[cur][i].weight;
                if(cost[next] == -1 || cost[next] > nextW){
                    cost[next] = nextW;
                    pq.push({next, nextW});
                }
            }
        }  
        printf("%.10f\n", cost[n-1]);
    }
    return 0;
}