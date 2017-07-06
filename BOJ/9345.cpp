#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int INF = 1e9;

int n, k;
int arr[MAXN+5];
int minT[MAXN*4+5];
int maxT[MAXN*4+5];

void build(int root, int l, int r)
{
    if(l == r){
        minT[root] = arr[l];
        maxT[root] = arr[l];
        return ;
    }
    int m = (l + r) / 2;
    build(root<<1, l, m);
    build(root<<1|1, m+1, r);
    minT[root] = min(minT[root<<1], minT[root<<1|1]);
    maxT[root] = max(maxT[root<<1], maxT[root<<1|1]);
}

int minq(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return INF;
    if(ql <= l && r <= qr) return minT[root];
    int m = (l + r) / 2;
    return min(minq(ql, qr, root<<1, l, m), minq(ql, qr, root<<1|1, m+1, r));
}

int maxq(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return -INF;
    if(ql <= l && r <= qr) return maxT[root];
    int m = (l + r) / 2;
    return max(maxq(ql, qr, root<<1, l, m), maxq(ql, qr, root<<1|1, m+1, r));
}

void update(int pos, int val, int root, int l, int r)
{
    if(l == r){
        minT[root] = val;
        maxT[root] = val;
        return ;
    }   
    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, root<<1, l, m);
    else update(pos, val, root<<1|1, m+1, r);
    minT[root] = min(minT[root<<1], minT[root<<1|1]);
    maxT[root] = max(maxT[root<<1], maxT[root<<1|1]);
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; ++i) arr[i] = i;
        build(1, 0, n-1);

        for(int i = 0; i < k; ++i){
            int q, a, b;
            scanf("%d %d %d",&q,&a,&b);
            if(q){
                if(a == minq(a, b, 1, 0, n-1) && b == maxq(a, b, 1, 0, n-1)) puts("YES");
                else puts("NO");
            }else{
                swap(arr[a], arr[b]);
                update(a, arr[a], 1, 0, n-1);
                update(b, arr[b], 1, 0, n-1);
            }
        }
    }
}