#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct state
{
    int ry, rx;
    int by, bx;  
    int dist;

    state (state _state)
    {
        ry = _state.ry;
        rx = _state.rx;
        by = _state.by;
        bx = _state.bx;
        dist = _state.dist;
    }

    state(){};
};

int n, m;
char board[11][11];

state direction(state s, int d)
{
    state s = tmp;

    //int nrx, nry, nbx, nry;
    int nc[4];
    nc[0] = tmp.rx; nc[1] = tmp.ry; nc[2] = tmp
    while(1)
    {
        if(!con) break;
    }
}

bool bfs(state inp)
{
    queue<state> q;
    q.push(inp);

    while(!q.empty())
    {
        state cur = q.front();
        q.pop();

        if(cur.dist > 10) continue;
        if(board[cur.by][cur.bx] == 'O') continue;
        if(board[cur.ry][cur.rx] == 'O') return true;

        for(int i = 0; i < 4; ++i){
            state tmp = direction(cur, i);
            q.push(tmp);
        }
    }
    return false;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s",board[i]);

    int iry, irx, iby, ibx;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 'B') {
                iby = i;
                ibx = j;
            }
            if(board[i][j] == 'R'){
                iry = i;
                irx = j;
            }
        }
    }

    state f;
    f.ry = iry; f.rx = irx; f.by = iby; f.bx = ibx;
    f.dist = 0;
    printf("%d\n",bfs(f));
}