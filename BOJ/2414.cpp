#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char board[55][55];
pair<int,int> rc[55][55];

int bM[2500];
bool visited[2500];
vector<int> g[2500];

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
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s",board[i]);


    int rIdx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            while(board[i][j] == '*' && j < m) rc[i][j++].first = rIdx;
            rIdx++;
        }
    }


    int cIdx = 0;
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            while(board[i][j] == '*' && i < n) rc[i++][j].second = cIdx;
            cIdx++;
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

    for(int i = 0; i < cIdx; ++i) bM[i] = -1;

    int ans = 0;
    for(int i = 0; i < rIdx; ++i){
        for(int j = 0; j < rIdx; ++j) visited[j] = false;
        if(dfs(i)) ans++;
    }
    printf("%d\n",ans);
}