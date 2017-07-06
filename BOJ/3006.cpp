#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

int n;
int a[MAXN+5];
int T[MAXN*4+5];

void build(int root, int l, int r)
{
    if(l == r){
        T[root] = 1;
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

int query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return query(ql, qr, root<<1, l, m) + query(ql, qr, root<<1|1, m+1, r);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);
        a[x] = i;
    }
    build(1, 0, n-1);

    for(int i = 0; i < n; ++i){
        int pos;
        if(i % 2){            
            pos = a[n-1 - i/2];
            printf("%d\n", query(0, max(0, pos-1), 1, 0, n-1));
        }else{
            pos = a[i/2];
            printf("%d\n", query(min(pos+1, n-1), n-1, 1, 0, n-1));
        }
        printf("pos : %d\n",pos);
        update(pos, 0, 1, 0, n-1);
    }
}