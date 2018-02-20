#include <bits/stdc++.h>

using namespace std;

int n;
string inp[105];
int out[26];
int in[26];
int edge[26][26];
vector<string> g[26][26];

bool check()
{
    int s = 0; int e = 0;
    for(int i = 0; i < 26; ++i){
        int d = out[i] - in[i];
        
        if(d < -1 || 1 < d) return false;
        if(d == 1) s++;
        if(d == -1) e++;
    }
    return (s == 1 && e == 1) || (s == 0 && e == 0);
}

void dfs(int cur, vector<int>& path)
{
    for(int nxt = 0; nxt < 26; ++nxt)
    {
        while(edge[cur][nxt]){
            edge[cur][nxt]--;
            dfs(nxt, path);
        }
    }
    path.push_back(cur);
}

vector<int> f()
{
    vector<int> circuit;
    
    for(int i = 0; i < 26; ++i){
        if(out[i] == in[i] + 1){
            dfs(i, circuit);
            return circuit;
        }
    }
    
    for(int i = 0; i < 26; ++i){
        if(out[i]){
            dfs(i, circuit);
            return circuit;
        }
    }

    return circuit;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 26; ++i) out[i] = in[i] = 0;

        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < 26; ++j){
                edge[i][j] = 0;
                g[i][j].clear();
            }
        }
        for(int i = 0; i < n; ++i){
            cin >> inp[i];

            int u = inp[i][0] - 'a';
            int v = inp[i][inp[i].size() - 1] - 'a';
            g[u][v].push_back(inp[i]);
            edge[u][v]++;
            out[u]++;
            in[v]++;
        }

        if(!check()) {
            puts("IMPOSSIBLE");
            continue;
        }

        vector<int> Epath = f();
        if(Epath.size() != n + 1) {
            puts("IMPOSSIBLE");
            continue;
        }
        reverse(Epath.begin(), Epath.end());

        string ans;
        for(int i = 1; i < (int)Epath.size(); ++i){
            int u = Epath[i-1];
            int v = Epath[i];

            ans += g[u][v].back() + " ";
            g[u][v].pop_back();
        }

        cout << ans << endl;
    }
}