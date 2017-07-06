#include <cstdio>
#include <vector>

using namespace std;

int n, vcnt;
int board[10][10];
int r[10][10];
int c[10][10];

int visited[105];
int bM[105];
vector<int> g[105];

int dfs(int cur)
{
    visited[cur] = vcnt;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int B = g[cur][i];
        if(bM[B] == -1 || visited[bM[B]] != vcnt && dfs(bM[B])){
            bM[B] = cur;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &board[i][j]);

    int rIdx = 1, cIdx = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(board[j][i-j]) r[j][i-j] = rIdx;
            if(board[n-j-1][i-j]) c[n-j-1][i-j] = cIdx;
        }
        rIdx++;
        cIdx++;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n-i; ++j){
            if(board[i+j][n-1-j]) r[i+j][n-1-j] = rIdx;
            if(board[n-j-1-i][n-j-1]) c[n-j-1-i][n-j-1] = cIdx;
        }
        rIdx++;
        cIdx++;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j]){
                int a = r[i][j];
                int b = c[i][j];
                g[a].emplace_back(b);
            }
        }
    }

    for(int i = 0; i <= cIdx; ++i) bM[i] = -1;
    int ans = 0; vcnt = 0;
    for(int i = 1; i <= rIdx; ++i) {
        ++vcnt;
        ans += dfs(i);
    }
    printf("%d\n",ans);    
}