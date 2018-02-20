#include <cstdio>
#include <vector>

using namespace std;

int n, m, t, a;
int aMatch[1005]; int bMatch[1005];
bool visited[1005];
bool g[1005][1005];

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;

    for(int i = 0; i < m; ++i){
        if(g[a][i]){
            if(bMatch[i] == -1 || dfs(bMatch[i])){
                aMatch[a] = i;
                bMatch[i] = a;
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
        for(scanf("%d",&t);t--;){
            scanf("%d",&a);
            g[i][a-1] = true;
        }
    }

    for(int i = 0; i < n; ++i) aMatch[i] = -1;
    for(int i = 0; i < m; ++i) bMatch[i] = -1;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int k = 0; k < 2; ++k){
            for(int j = 0; j < n; ++j) visited[j] = false;
            if(dfs(i)) ans++;
        }
    }
    printf("%d\n",ans);
}