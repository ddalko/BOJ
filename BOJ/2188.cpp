#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
const int MAXM = 200;

int N, M, s, a;
int Capacity[MAXN+MAXM+5][MAXN+MAXM+5];
int Flow[MAXN+MAXM+5][MAXN+MAXM+5];

int main()
{
    scanf("%d %d",&N,&M);

    for(int i = 0; i < M; ++i) Capacity[N+i+1][N+M+1] = 1;
    for(int i = 0; i < N; ++i){
        Capacity[0][i+1] = 1;
        scanf("%d",&s);
        for(int j = 0; j < s; ++j) {
            scanf("%d",&a);
            Capacity[i+1][N+a] = 1;
        }
    }

    int ans = 0;
    while(true)
    {
        vector<int> parent(MAXN+MAXM+5, -1);
        queue<int> q;
        parent[0] = 0;
        q.push(0);

        while(!q.empty() && parent[N+M+1] == -1){
            int cur = q.front(); q.pop();
            
            for(int nxt = 0; nxt < N+M+2; ++nxt){
                if(Capacity[cur][nxt] - Flow[cur][nxt] > 0 && parent[nxt] == -1){
                    q.push(nxt);
                    parent[nxt] = cur;
                }
            }
        }

        if(parent[N+M+1] == -1) break;

        int amount = 1e9;
        for(int p = N+M+1; p != 0; p = parent[p]){
            amount = min(Capacity[parent[p]][p] - Flow[parent[p]][p], amount);
        }

        for(int p = N+M+1; p != 0; p = parent[p]){
            Flow[parent[p]][p] += amount;
            Flow[p][parent[p]] -= amount;
        }
        ans += amount;
    }
    printf("%d\n",ans);
}