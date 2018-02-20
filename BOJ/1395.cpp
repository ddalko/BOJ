#include <cstdio>

const int MAXN = 100000;

int n, m;
int a, b, c;
int tree[MAXN*4];

int query(int s, int e, int idx, int l, int r)
{
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[idx];
    int m = (s + e) / 2;
    return query(s, m, idx*2+1, l, r) + query(m+1, e, idx*2+2, l, r);
}

void update(int s, int e, int idx, int l, int r)
{
    if(r < s || e < l) return ;
    if(s == e){
        tree[idx] ^= 1;
        return ;
    }

    int m = (s + e) / 2;
    update(s, m, idx*2+1, l, r);
    update(m+1, e, idx*2+2, l, r);
    tree[idx] = tree[idx*2+1] + tree[idx*2+2];
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d",&a,&b,&c);
        if(a == 0) update(0, n-1, 0, b-1, c-1);
        else if(a == 1) printf("%d\n",query(0, n-1, 0, b-1, c-1));
    }
}