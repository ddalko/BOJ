#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m;
int price[200005];
priority_queue<pii, vector<pii>, greater<pii> > pq[3];
bool v[200005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d",price+i);
    for(int i = 0; i < n; ++i) {
        int ai;
        scanf("%d",&ai);
        pq[ai-1].push(make_pair(price[i], i));
    }

    for(int i = 0; i < n; ++i) {
        int bi;
        scanf("%d",&bi);
        pq[bi-1].push(make_pair(price[i], i));
    }

    scanf("%d",&m);
    for(int i = 0; i < m; ++i){
        int x;
        scanf("%d",&x);

        while(!pq[x-1].empty() && v[pq[x-1].top().second]) pq[x-1].pop();
        if(pq[x-1].empty()) printf("-1 ");
        else{
            printf("%d ",pq[x-1].top().first);
            v[pq[x-1].top().second] = true;
            pq[x-1].pop();
        }
    }
}