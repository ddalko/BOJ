#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int Answer;
int n, m;
int V;
vector<int> G[40005];
vector<int> rG[40005];
vector<int> vs;
bool used[40005];
int cmp[40005];

inline int Not(int x)
{
    return x < (V / 2) ? x + (V / 2) : x - (V / 2);
}

void add_edge(int u, int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}

void dfs(int v)
{
    used[v] = true;
    for(int i = 0; i < (int)G[v].size(); ++i){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < (int)rG[v].size(); ++i){
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

void scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < V; ++v){
        if(!used[v]) dfs(v);
    }

    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = vs.size() - 1; i >= 0; --i){
        if(!used[vs[i]]) rdfs(vs[i], k++);
    }
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
        cin >> n >> m;
        V = n * m * 4;

        for(int i = 0; i < V; ++i) {
            G[i].clear();
            rG[i].clear();
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int f, a, b;
                cin >> f >> a >> b;
                int r = n * m + i * m + a;
                int c = b * m + j;
                
                if(f){       
                    //r -> c
                    add_edge(r, c);
                    //c -> r
                    add_edge(c, r);
                    //!r -> !c
                    add_edge(Not(r), Not(c));
                    //!c -> !r
                    add_edge(Not(c), Not(r));
                }else{
                    //!r -> c
                    add_edge(Not(r), c);
                    //!c -> r
                    add_edge(Not(c), r);
                    //r -> !c
                    add_edge(r, Not(c));
                    //c -> !r
                    add_edge(c, Not(r));
                }
            }
        }

        scc();

        bool flag = false;
        for(int i = 0; i < V / 2; ++i){
            if(cmp[i] == cmp[Not(i)]){
                flag = true;
                break;
            }
        }
        
		cout << "Case #" << test_case+1 << '\n';
        if(flag) cout << "Impossible" << '\n';
        else{
            for(int i = 0; i < V / 4; ++i){
                if(cmp[i] > cmp[Not(i)]){
                    printf("C%02d%02d ", i % m, i / m);
                }
            }
            for(int i = V / 4; i < V / 2; ++i){
                if(cmp[i] > cmp[Not(i)]){
                    printf("R%02d%02d ", (i - V / 4) / m, (i - V / 4) % m);
                }
            }
            cout << '\n';
        }
    }

	return 0;//Your program should return 0 on normal termination.
}