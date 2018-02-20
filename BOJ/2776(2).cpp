#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k;
int arr[1000005];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i) scanf("%d",arr+i);
        sort(arr, arr+n);
        scanf("%d",&m);
        for(int i = 0; i < m; ++i){
            scanf("%d",&k);

            int lb = -1; int ub = n;
            while(ub - lb > 1){
                int m = (lb + ub) / 2;
                if(arr[m] >= k) lb = m;
                else ub = m;
            }
            printf("%d %d %d\n",arr[lb],arr[ub],arr[(lb+ub)/2]);
            if(k == arr[(lb+ub)/2]) puts("1");
            else puts("0");
        }
    }
}