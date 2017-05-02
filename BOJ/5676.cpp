#include <cstdio>

const int MAXN = 100000;

int n, k;
int arr[MAXN+5];
int tree[MAXN*4];

void build(int id, int l, int r)
{
    if(r == l) {
        tree[id] = arr[l];
        return ;
    }
    int m = (r + l) / 2;
    build(id*2+1, l, m);
    build(id*2+2, m+1, r);
    tree[id] = tree[id*2+1] * tree[id*2+2];
}

int query(int s, int e, int id, int l, int r)
{
    if(r < s || e < l) return 1;
    if(l <= s && e <= r) return tree[id];

    int m = (s + e) / 2;
    return query(s, m, id*2+1, l, r) * query(m+1, e, id*2+2, l, r);
}

void update(int pos, int val, int id, int l, int r)
{
    if(l == r){
        tree[id] = (val > 0) ? 1 : (val == 0) ? 0 : -1;
        return ;
    }

    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, id*2+1, l, m);
    else update(pos, val, id*2+2, m+1, r);

    tree[id] = tree[id*2+1] * tree[id*2+2];
}

int main()
{
    while(scanf("%d %d",&n,&k) != -1){
        for(int i = 0; i < n; ++i) arr[i] = tree[i] = 0;

        for(int i = 0; i < n; ++i) {
            int a;
            scanf("%d",&a);
            arr[i] = (a > 0) ? 1 : (a == 0) ? 0 : -1;
        }
        build(0, 0, n-1);

        char op; int a, b;
        while(k--){
            scanf(" %c %d %d",&op,&a,&b);
            if(op == 'C') update(a-1, b, 0, 0, n-1);
            else if(op == 'P') {
                int res = query(0, n-1, 0, a-1, b-1);
                if(res > 0) printf("+");
                else if(res == 0) printf("0");
                else printf("-");
            }
        }
        puts("");
    }
}