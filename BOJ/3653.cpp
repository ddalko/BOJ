#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100000;
const int MAXM = 100000;

int n, m;
int pos[MAXN+5];
int T[(MAXN+MAXM)*4+5];

void update(int pos, int val, int root, int l, int r)
{
    if(l == r){
        T[root] = val;
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, root<<1, l, m);
    else update(pos, val, root<<1|1, m+1, r);
    T[root] = T[root<<1] + T[root<<1|1];
}

int query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return query(ql, qr, root<<1, l, m) + query(ql, qr, root<<1|1, m+1, r);
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        memset(T, 0, sizeof(T));
        scanf("%d %d",&n,&m);
        int node = n + m;

        for(int i = 1; i <= n; ++i) {
            pos[i] = n-i;
            update(pos[i], 1, 1, 0, node-1);
        }

        for(int i = 0; i < m; ++i){
            int x;
            scanf("%d",&x);
            printf("%d ",query(pos[x], node-1, 1, 0, node-1)-1);
            update(pos[x], 0, 1, 0, node-1);
            pos[x] = n + i;
            update(pos[x], 1, 1, 0, node-1);
        }
        puts("");
    }
}