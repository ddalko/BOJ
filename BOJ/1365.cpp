#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
typedef pair<int,int> pii;

int n;
int T[MAXN*4+5];

bool cmp(const pii A, const pii B)
{
    if(A.first != B.first) return A.first < B.first;
    return A.second > B.second;
}

int query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return max(query(ql, qr, root<<1, l, m), query(ql, qr, root<<1|1, m+1, r));
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
    T[root] = max(T[root<<1], T[root<<1|1]);
}

int main()
{
    scanf("%d",&n);
    vector<pii> A(n);

    for(int i = 0; i < n; ++i){
        scanf("%d",&A[i].first);
        A[i].second = i;
    }
    sort(A.begin(), A.end(), cmp);

    for(int i = 0; i < n; ++i){
        int lis = query(0, A[i].second, 1, 0, n-1);       
        update(A[i].second, lis+1, 1, 0, n-1);
    }
    printf("%d\n", n - T[1]);
}