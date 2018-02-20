#include <bits/stdc++.h>

using namespace std;

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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
char board[105][105];
int w[101][101];

int dijkstra()
{
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) w[i][j] = 1e9;

    priority_queue<P> pq;
    w[0][0] = board[0][0] - '0';
    P src = {0, 0, w[0][0]};
    pq.push(src);

    while(!pq.empty()){
        int curX = pq.top().x;
        int curY = pq.top().y;
        int cost = pq.top().c;
        pq.pop();

        if(curX == m-1 && curY == n-1) return w[n-1][m-1];
        if(w[curY][curX] < cost) continue;

        for(int i = 0; i < 4; ++i){
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if(m <= nX || nX < 0 || n <= nY || nY < 0) continue;

            int nCost = cost + (board[nY][nX] - '0');
            if(w[nY][nX] > nCost){
                w[nY][nX] = nCost;
                P nxt = {nX, nY, nCost};
                pq.push(nxt);
            }
        }
    }
    return w[n-1][m-1];
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; ++i) scanf("%s",board[i]);

    int ans = dijkstra();
    printf("%d\n",ans);
}