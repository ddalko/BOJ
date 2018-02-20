#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct P{
    int x;
    int y;
    int c;

    bool operator< (const P rhs) const
    {
        if(c == rhs.c) {
            if(x == rhs.x) return y < rhs.y;
            return x < rhs.x;
        }
        return c > rhs.c;
    }
};

int n;
int dist[126][126];
int g[126][126];

int bfs()
{
    priority_queue<P> pq;
    dist[0][0] = g[0][0];
    P src = {0, 0, g[0][0]};
    pq.push(src);

    while(!pq.empty()){
        int curX = pq.top().x;
        int curY = pq.top().y;
        int cost = pq.top().c;
        pq.pop();

        if(dist[curY][curX] < cost) continue;

        for(int i = 0; i < 4; ++i){
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            int nxtCost = cost + (g[nY][nX] - '0');

            if(0 <= nX && nX < n && 0 <= nY && nY < n){
                if(dist[nY][nX] > nxtCost){
                    dist[nY][nX] = nxtCost;
                    P nxt = {nX, nY, nxtCost};
                    pq.push(nxt);
                }
            }
        }
    }
    return dist[n-1][n-1];
}

int main()
{
    int t = 1;
    while(scanf("%d",&n), n!=0){
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d",&g[i][j]);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) dist[i][j] = 1e9;

        int ans = bfs();
        printf("Problem %d: %d\n",t++,ans);
    }
}