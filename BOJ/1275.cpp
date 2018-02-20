#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

int n, q;
int arr[MAXN+5];
long long T[MAXN*4+5];

void build(int root, int l, int r)
{
    if(l == r){
        T[root] = arr[l];
        return ;
    }
    int m = (l + r) / 2;
    build(root<<1, l, m);
    build(root<<1|1, m+1, r);
    T[root] = T[root<<1] + T[root<<1|1];
}

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

long long query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return query(ql, qr, root<<1, l, m) + query(ql, qr, root<<1|1, m+1, r);
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);
    build(1, 0, n-1);

    for(int i = 0; i < q; ++i){
        int x, y, a, b;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        printf("%lld\n", query(min(x-1,y-1), max(x-1,y-1), 1, 0, n-1));
        update(a-1, b, 1, 0, n-1);
    }
}