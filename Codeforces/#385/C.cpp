#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int vcnt;
int n, m, k;
int C[1005];
vector<int> G[1005];

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(int cur)
{
    C[cur] = vcnt;

    for(int i = 0; i < (int)G[cur].size(); ++i){
        int nxt = G[cur][i];
        if(C[nxt] < 0) dfs(nxt);
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    vector<int> gov;
    for(int i = 0; i < k; ++i) {
        int x;
        scanf("%d ",&x);
        gov.push_back(x);
    }

    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        add_edge(a, b);
    }

    //Seperate Components
    vcnt = 0;
    for(int i = 0; i <= n; ++i) C[i] = -1;
    for(int i = 1; i <= n; ++i){
        if(C[i] < 0){
            dfs(i);
            vcnt++;
        }
    }

    //Sort by size
    vector<int> Csz(vcnt, 0);
    for(int i = 1; i <= n; ++i) Csz[C[i]]++;
    
    vector<bool> isGov(vcnt, false);
    for(int i = 0; i < (int)gov.size(); ++i) isGov[C[gov[i]]] = true;

    vector<int> govSize;
    int norSize = 0;
    int ans = 0;
    for(int i = 0; i < vcnt; ++i){
        if(isGov[i]) govSize.push_back(Csz[i]);
        else {
            norSize += Csz[i];
            if(ans == 0) ans += Csz[i];
            else ans *= Csz[i];
        }
    }

    sort(govSize.begin(), govSize.end(), greater<int>());
    ans += norSize * govSize[0];
    printf("%d\n", ans);
}