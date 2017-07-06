#include <cstdio>
using namespace std;
const int MAXN = 1000000;

int n, q;
long long T[MAXN*4+5];

void update(int pos, int val, int root, int l, int r)
{
    if(l == r){
        T[root] += val;
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
    for(int i = 0; i < q; ++i){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        if(a == 1){
            update(b-1, c, 1, 0, n-1);
        }else if(a == 2){
            printf("%lld\n", query(b-1, c-1, 1, 0, n-1));
        }
    }
    
}