#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 200;
const int MAXM = 200;

int n, m, s, x;
vector<bool> visited;
vector<int> aMatch, bMatch;
bool adj[MAXN+5][MAXM+5];

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;

    for(int b = 0; b < m; ++b){
        if(adj[a][b]){
            if(bMatch[b] == -1 || dfs(bMatch[b])){
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i){
        for(scanf("%d",&s);s--;){
            scanf("%d",&x);
            adj[i][x-1] = true;
        }
    }

    int size = 0;
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    for(int i = 0; i < n; ++i){
        visited = vector<bool>(n, false);
        if(dfs(i)) size++;
    }

    printf("%d\n",size);
}