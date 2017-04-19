#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m;
int dist[105];
bool g[105][105];

int bfs(int node)
{
    for(int i = 0; i < n; ++i) dist[i] = 0;

    queue<pair<int,int> > q;
    q.push(make_pair(node, 0));
    dist[node] = 1;

    while(!q.empty()){
        int cur = q.front().first;
        int s = q.front().second;
        q.pop();

        for(int nxt = 0; nxt < n; ++nxt)
        {
            if(g[cur][nxt] && !dist[nxt]){
                q.push(make_pair(nxt, s+1));
                dist[nxt] = s+1;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; ++i) ret += dist[i];
    return ret-1;
}

int main()
{ 
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = g[b-1][a-1] = true;
    }

    int MIN = INF; int aIdx = -1; 
    for(int i = 0; i < n; ++i) {
        int cmp = bfs(i);
        if(cmp < MIN){
            MIN = cmp;
            aIdx = i+1;
        }
    }
    printf("%d\n", aIdx);
}