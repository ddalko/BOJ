#include <cstdio>
#include <vector>

using namespace std;

int n, vcnt;
char board[10][10];
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
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i) scanf("%s",board[i]);

        int rIdx = 0, cIdx = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(board[j][i-j] == '.'){
                    if(j==0 || board[j-1][i-j+1] == '*') ++rIdx;
                    r[j][i-j] = rIdx;
                }
                if(board[n-j-1][i-j] == '.'){
                    if(j==0 || board[n-j][i-j+1] == '*') ++cIdx;
                    c[n-j-1][i-j] = cIdx;
                }
            }
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n-i; ++j){
                if(board[i+j][n-1-j] == '.'){
                    if(j==0 || board[i+j-1][n-j] == '*') ++rIdx;
                    r[i+j][n-1-j] = rIdx;
                }
                if(board[n-j-1-i][n-j-1] == '.'){
                    if(j==0 || board[n-j-i][n-j] == '*') ++cIdx;
                    c[n-j-1-i][n-j-1] = cIdx;
                }
            }
        }
        for(int i = 0; i <= rIdx; ++i) g[i].clear();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == '.'){
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
}