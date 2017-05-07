#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, vcnt;
char board[55][55];
pair<int,int> rc[55][55];

int visited[2505];
int bM[2505];
vector<int> g[2505];

int dfs(int cur)
{
    if(visited[cur] == vcnt) return 0;
    visited[cur] = vcnt;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int B = g[cur][i];
        if(bM[B] == -1 || dfs(bM[B])){
            bM[B] = cur;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s",board[i]);

    int rIdx = 0, cIdx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == '*'){
                if(j == 0 || board[i][j-1] == '.') rIdx++;
                rc[i][j].first = rIdx;
            }
        }
    }

    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            if(board[i][j] == '*'){
                if(i == 0 || board[i-1][j] == '.') cIdx++;
                rc[i][j].second = cIdx;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == '*'){
                int a = rc[i][j].first;
                int b = rc[i][j].second;
                g[a].emplace_back(b);
            }
        }
    }

    int ans = 0; vcnt = 0;
    for(int i = 0; i <= cIdx; ++i) bM[i] = -1;

    for(int i = 0; i <= rIdx; ++i){
        ++vcnt;
        ans += dfs(i);
    }
    printf("%d\n",ans);
}