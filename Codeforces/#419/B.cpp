#include <cstdio>

int n, k, q;
int arr[200001];
int tree[200000*4];

void build(int id, int l, int r)
{
    if(r == l) {
        tree[id] = (arr[l] >= k) ? 1 : 0;
        return ;
    }
    int m = (r + l) / 2;
    build(id*2+1, l, m);
    build(id*2+2, m+1, r);
    tree[id] = tree[id*2+1] + tree[id*2+2];
}

int query(int s, int e, int id, int l, int r)
{
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[id];

    int m = (s + e) / 2;
    return query(s, m, id*2+1, l, r) + query(m+1, e, id*2+2, l, r);
}

int main()
{
    scanf("%d %d %d",&n,&k,&q);
    for(int i = 0; i < n; ++i){
        int l, r;
        scanf("%d %d",&l,&r);
        for(int j = l; j <= r; ++j) arr[j]++;
    }
    build(0, 0, 200001);

    int ql, qr;
    for(int i = 0; i < q; ++i){
        scanf("%d %d",&ql,&qr);
        printf("%d\n",query(0, 200001, 0, ql, qr));
    }
}