#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4000;
int n;
int a[MAXN+5];
int b[MAXN+5];
int c[MAXN+5];
int d[MAXN+5];
int cd[MAXN*MAXN + 5];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d %d %d %d",a+i,b+i,c+i,d+i);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cd[i * n + j] = c[i] + d[j];
        }
    }
    sort(cd, cd + n*n);

    long long res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int ab = -(a[i] + b[j]);
            res += upper_bound(cd, cd+n*n, ab) - lower_bound(cd, cd+n*n, ab);
        }
    }
    printf("%lld\n",res);
}