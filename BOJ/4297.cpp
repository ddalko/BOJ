#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 500000;

int n;
int a[MAXN+5];
int tree[MAXN*4+5];

void build(int root, int l, int r)
{
    if(l == r){
        tree[root] = 0;
        return ;
    }
    int m = (l + r) / 2;
    build(root << 1, l, m);
    build(root << 1 | 1, m+1, r);
    tree[root] = 0;
}

void update(int pos, int val, int root, int l, int r)
{
    if(l == r){
        tree[root] += val;
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, root<<1, l, m);
    else update(pos, val, root<<1|1, m+1, r);
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

int query(int ql, int qr, int root, int l, int r)
{
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return tree[root];
    int m = (l + r) / 2;
    return query(ql, qr, root<<1, l, m) + query(ql, qr, root<<1|1, m+1, r);
}

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n == 0) break;

        build(1, 0, n-1);
        for(int i = 0; i <= n; ++i) a[i] = 0;
        vector<int> b;

        for(int i = 0; i < n; ++i) {
            scanf("%d",a+i);
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());

        long long ans = 0;
        for(int i = 0; i < n; ++i){
            int sIdx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            ans += query(min(sIdx+1, n-1), n-1, 1, 0, n-1);
            update(sIdx, 1, 1, 0, n-1);
        }
        printf("%lld\n",ans);
    }
}
