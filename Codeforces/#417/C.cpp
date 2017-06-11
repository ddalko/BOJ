#include <cstdio>
#include <algorithm>

using namespace std;

int n, s;
int arr[100005];
int sarr[100005];

int main()
{
    scanf("%d %d",&n,&s);

    for(int i = 0; i < n; ++i) scanf("%d",arr+i);

    int ans = 0;
    int ansSum = 0;
    for(int k = 1; k <= n; ++k){

        for(int i = 0; i < n; ++i){
            sarr[i] = arr[i] + (i+1) * k;
        }
        sort(sarr, sarr+n);

        int sum = 0;
        for(int i = 0; i < k; ++i){
            sum += sarr[i];
        }

        if(sum <= s){
            ansSum = sum;
            ans = k;
        }else{
            break;
        }
    }
    printf("%d %d\n",ans,ansSum);
}