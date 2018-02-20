#include <cstdio>
const int MAXN = 20000;

int T[MAXN*4+5];

void update(int pos, int root = 1, int l = 0, int r = MAXN)
{
    if(l == r){
        T[root] += 1;
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, root<<1, l, m);
    else update(pos, root<<1|1, m+1, r);
    T[root] = T[root<<1] + T[root<<1|1];
}

int query(int k, int root = 1, int l = 0, int r = MAXN)
{
    if(l == r) return l;
    int m = (l + r) / 2;
    if(k <= T[root<<1]) return query(k, root<<1, l, m);
    else return query(k - T[root<<1], root<<1|1, m+1, r);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);
        update(x + 10000);
        printf("%d\n", query(i/2+1) - 10000);
    }
}