#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 100000;

int n;
int T[MAXN*4+5];

int query(int ql, int qr, int root, int l, int r)
{
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return T[root];
    int m = (l + r) / 2;
    return max(query(ql, qr, root<<1, l, m), query(ql, qr, root<<1|1, m+1, r));
}

void update(int pos, int val, int root, int l, int r)
{
    if(l == r) {
        T[root] = val;
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, val, root<<1, l, m);
    else update(pos, val, root<<1|1, m+1, r);
    T[root] = max(T[root<<1], T[root<<1|1]);
}

bool cmp(const pii A, const pii B)
{
    if(A.first != B.first) return A.first < B.first;
    return A.second > B.second;
}

int main()
{
    while(1)
    {
        cin >> n;
        if(cin.eof()) break;

        memset(T, 0, sizeof(T));
        vector<pii> v(n);
        for(int i = 0; i < n; ++i) {
            scanf("%d",&v[i].first);
            v[i].second = i;
        }
        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < n; ++i){
            int val = query(0, v[i].second, 1, 0, n-1);
            update(v[i].second, val+1, 1, 0, n-1);
        }
        cout << T[1] << '\n';
    }
}