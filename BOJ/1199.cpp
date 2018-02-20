#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, v;
int g[1004][1004];
vector<int> ans;

void dfs(int cur)
{
    for(int nxt = 0; nxt < n; ++nxt)
    {
        while(g[cur][nxt] > 0){
            g[cur][nxt]--;
            g[nxt][cur]--;
            dfs(nxt);
        }
    }
    ans.push_back(cur);
}

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i){
        int deg = 0;
        for(int j = 0; j < n; ++j){
            scanf("%d",&v);
            g[i][j] = v; 
            deg += v;
        }

        if(deg % 2){
            puts("-1");
            return 0;
        }
    }
    dfs(0);
    for(int i = 0; i < (int)ans.size(); ++i) printf("%d ",ans[i]+1);
}