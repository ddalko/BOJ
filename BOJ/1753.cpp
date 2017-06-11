#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int v, e, src;
int dist[20005];
int in_q[20005];
vector<pii> g[20005];

void spfa(int src)
{
    for(int i = 0; i <= v; ++i) dist[i] = 1e9;
    
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    in_q[src] = true;

    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        in_q[curNode] = false;
    
        for(int i = 0; i < (int)g[curNode].size(); ++i){
            int nxtNode = g[curNode][i].first;
            int nxtCost = g[curNode][i].second;

            if(dist[nxtNode] > dist[curNode] + nxtCost)
            {
                dist[nxtNode] = dist[curNode] + nxtCost;

                if(!in_q[nxtNode]){
                    q.push(nxtNode);
                    in_q[nxtNode] = true;
                }
            }
        }
    }   
}

int main()
{
    scanf("%d %d %d",&v,&e,&src);
    for(int i = 0; i < e; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1].emplace_back(b-1, c);
    }

    spfa(src-1);
    for(int i = 0; i < v; ++i) {
        if(dist[i] == 1e9) puts("INF");
        else printf("%d\n", dist[i]);
    }
}