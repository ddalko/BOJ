#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000;
const int M = 1000;

int n, m;
bool visited[M+5];
int bMatched[N+5];
vector<int> g[M+5];

bool dfs(int cur)
{
    visited[cur] = true;

    for(int i = 0; i < (int)g[cur].size(); ++i){
        int B = g[cur][i];
        if(bMatched[B] == -1 || !visited[bMatched[B]] && dfs(bMatched[B])){
            bMatched[B] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d",&n,&m);

        for(int i = 0; i <= n; ++i) bMatched[i] = -1;
        for(int i = 0; i <= m; ++i) g[i].clear();
        
        for(int i = 1; i <= m; ++i){
            int a, b;
            scanf("%d %d",&a,&b);
            for(int j = a; j <= b; ++j) g[i].push_back(j);
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = 0; j <= m; ++j) visited[j] = false;
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
}