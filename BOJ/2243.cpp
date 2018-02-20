#include <cstdio>
using namespace std;
const int MAXT = 1000000;

int T[MAXT*4+5];

void update(int pos, int val, int root = 1, int l = 0, int r = MAXT)
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

int knum(int k, int root = 1, int l = 0, int r = MAXT)
{
    if(l == r) return l;
    int m = (l + r) / 2;
    if(k <= T[root<<1]) return knum(k, root<<1, l, m);
    else return knum(k - T[root<<1], root<<1|1, m+1, r);
}

int main()
{
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; ++i){
        int a, b, c;
        scanf("%d %d",&a,&b);
        if(a == 1){
            if(b > T[1]) continue;
            //find b-th taste            
            int v = knum(b);
            printf("%d\n", v);
            //and update
            update(v, -1);
        }else if(a == 2){
            scanf("%d",&c);
            update(b, c);
        }
    }
}