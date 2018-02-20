#include <vector>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int N, k;
const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {0, 0, -1, 0, 1};

int temp[15][15];
int disc[15][15][15][15];

struct state
{
    int ax, ay;
    int bx, by;
    state(int _ax, int _ay, int _bx, int _by) : ax(_ax), ay(_ay), bx(_bx), by(_by) {}
};

bool isPossible(int nAx, int nAy, int nBx, int nBy, int n)
{
    int aRangeOut = (nAx < 0 || nAx >= n || nAy < 0 || nAy >= n) ? 1 : 0;
    int bRangeOut = (nBx < 0 || nBx >= n || nBy < 0 || nBy >= n) ? 1 : 0;
    if(aRangeOut || bRangeOut) return false;

    if(temp[nAy][nAx] == 1 || temp[nBy][nBx] == 1) return false;
    if(temp[nAy][nAx] == 3 || temp[nBy][nBx] == 3) return false;

    if(nAy == nBy && nAx == nBx) return false;

    return true;
}

int bfs(int Ax, int Ay, int Bx, int By, int n)
{
    queue<state> q;
    state init(Ax, Ay, Bx, By);
    disc[Ax][Ay][Bx][By] = 1;
    q.push(init);

    int ret = 0;
    while(!q.empty())
    {
        state curState = q.front();
        q.pop();

        if(temp[curState.ay][curState.ax] == 0 && temp[curState.by][curState.bx] == 0) {
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    printf("%d ",temp[i][j]);
                }
                puts("");
            }

            cout << "A : " << curState.ay << " " << curState.ax << endl;
            cout << "B : " << curState.by << " " << curState.bx << endl;
            cout << "step : " << ret << endl;
            return ret;
        }

        for(int i = 0; i < 5; ++i){
            int nAy = curState.ay + dy[i];
            int nAx = curState.ax + dx[i];

            for(int j = 0; j < 5; ++j){
                if(i == 0 && j == 0) continue;
                int nBy = curState.by + dy[j];
                int nBx = curState.bx + dx[j];
                
                if(isPossible(nAx, nAy, nBx, nBy, n)) {       
                    if(disc[nAx][nAy][nBx][nBy]) continue;                     
                    state nxtState(nAx, nAy, nBx, nBy);
                    cout << "cur" << endl;
                    cout << curState.ay << curState.ax << " " << curState.by << curState.bx << endl;
                    cout << "nxt" << endl;
                    cout << nAy << nAx << " " << nBy << nBx << endl;
                    q.push(nxtState);
                    disc[nAx][nAy][nBx][nBy] = 1;
                }
            }
        }
        ret++;
    }
    return -1;
}

int solution(vector<vector<int> > board, int K, int Ax, int Ay, int Bx, int By) {
	int answer = 0;

    for(int i = 0; i < N; ++i){
        vector<int> tmp;
        for(int j = 0; j < N; ++j){
            int a;
            scanf("%d", &a);
            tmp.push_back(a);
        }
        board.push_back(tmp);
    }

    int n = board.size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            temp[i][j] = board[i][j];
        }   
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 1){
                temp[i][j] = 3;
                for(int d = 1; d < 5; ++d){
                    for(int kk = 1; kk <= K; ++kk){
                        int nx = j + dx[d] * kk;
                        int ny = i + dy[d] * kk; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;                        
                        if(board[ny][nx] == 2) break;
                        temp[ny][nx] = 1;
                    }
                }
            }
        }
    }

    answer = bfs(Ax, Ay, Bx, By, n);

	return answer;
}

int main()
{
    scanf("%d %d",&N,&k);
    int x[4];
    for(int i = 0; i < 4; ++i) scanf("%d",x+i);

    vector<vector<int> > bb;
    printf("%d\n",solution(bb, k, x[0], x[1], x[2], x[3]));
}