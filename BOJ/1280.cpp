#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
const int MOD = 1000000007;

int n;
int cT[MAXN*4+5];
long long sT[MAXN*4+5];

void update(int pos, int root, int l, int r)
{
    if(l == r){
        cT[root] += 1;
        sT[root] += pos;
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, root<<1, l, m);
    else update(pos, root<<1|1, m+1, r);
    cT[root] = cT[root<<1] + cT[root<<1|1];
    sT[root] = sT[root<<1] + sT[root<<1|1];
}

int cnt(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return cT[root];
    int m = (l + r) / 2;
    return cnt(ql, qr, root<<1, l, m) + cnt(ql, qr, root<<1|1, m+1, r);
}

long long sum(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return sT[root];
    int m = (l + r) / 2;
    return sum(ql, qr, root<<1, l, m) + sum(ql, qr, root<<1|1, m+1, r);
}

int main()
{
    int maxi = 200000;
    int x;
    scanf("%d",&n);
    scanf("%d",&x);
    update(x, 1, 0, maxi+1);

    long long ans = 0;
    for(int i = 1; i < n; ++i){
        scanf("%d",&x);
        cout << cnt(0, n-1, 1, 0, maxi) << endl;
        cout << sum(0, n-1, 1, 0, maxi) << endl;
        cout << endl;
        long long left = cnt(0, x-1, 1, 0, maxi+1) * x - sum(0, x-1, 1, 0, maxi+1);
        long long right = sum(x+1, n-1, 1, 0, maxi+1) - cnt(x+1, n-1, 1, 0, maxi+1) * x;
        
        update(x, 1, 0, maxi+1);
        ans += (left % MOD + right % MOD) % MOD;
    }
    cout << ans << endl;
}