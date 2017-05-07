#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int A[20005];
int B[20005];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; ++i) scanf("%d",A+i);
        for(int i = 0; i < m; ++i) scanf("%d",B+i);
        sort(A, A+n); sort(B, B+m);
        
        int ans = 0;
        int lp = 0; int rp = 0;

        while(lp < n){
            if(A[lp] <= B[rp]){
                ans += rp;
                lp++;
            }
            else if(A[lp] > B[rp]) {
                if(rp < m) rp++;
                else{
                    ans += m * (n - lp);
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
}