#include <cstdio>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n;
long long S, sum;
int arr[100005];

int main()
{
    scanf("%d %lld",&n,&S);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);

    int ans = 1e9;
    int l = 0; int r = 0;
    sum = 0;
    while(l <= r && l < n && r < n){
        if(S <= sum){            
            ans = min(ans, r-l);
            sum -= arr[l++];
        }
        else {
            sum += arr[r++];
        }
    }
    if(ans != 1e9) printf("%d\n",ans);
    else puts("0");
}