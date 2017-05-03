#include <cstdio>
#include <vector>

using namespace std;

int r, c, n;
bool board[305][305];

bool visited[305];
int bM[305];
vector<int> g[305];

bool dfs(int cur)
{
    visited[cur] = true;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int B = g[cur][i];
        if(bM[B] == -1 || !visited[bM[B]] && dfs(bM[B])){
            bM[B] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d %d",&r,&c,&n);
    for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) board[i][j] = 1;
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        board[a-1][b-1] = 0;
    }

    for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(board[i][j]) g[i].emplace_back(j);
    for(int i = 0; i < c; ++i) bM[i] = -1;

    int ans = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < r; ++j) visited[j] = false;
        if(dfs(i)) ans++;
    }
    printf("%d\n",ans);
}