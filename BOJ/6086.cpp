#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 52;
const int INF = 1e9;

int n;
int C[MAXV][MAXV];
int F[MAXV][MAXV];

int f(char inp)
{
    if(inp >= 'a') return inp - 'a' + 26;
    else return inp - 'A';
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        char a, b; int c;
        scanf(" %c %c %d",&a,&b,&c);
        C[f(a)][f(b)] += c;
    }

    int ans = 0;
    while(true)
    {
        vector<int> parent(MAXV, -1);
        queue<int> q;

        q.push('A'-'A');
        parent['A'-'A'] = 'A'-'A';

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nxt = 0; nxt < MAXV; ++nxt){
                if(parent[nxt] == -1 && C[cur][nxt] - F[cur][nxt] > 0){
                    q.push(nxt);
                    parent[nxt] = cur;
                }
            }
        }

        if(parent['Z'-'A'] == -1) break;

        int amount = INF;
        for(int p = 'Z'-'A'; p != 0; p = parent[p]){
            amount = min(amount, C[parent[p]][p] - F[parent[p]][p]);
        }

        for(int p = 'Z'-'A'; p != 0; p = parent[p]){
            F[parent[p]][p] += amount;
            F[p][parent[p]] -= amount;
        }
        ans += amount;
    }
    printf("%d\n",ans);
}