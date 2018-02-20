#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int arr[15005];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);
    sort(arr, arr+n);

    int lp = 0; int rp = n-1;
    int ans = 0;
    while(lp < rp){
        if(arr[lp] + arr[rp] < m){
            lp++;
        }else if(arr[lp] + arr[rp] == m){
            ans++;
            lp++;
            rp--;
        }else{
            rp--;
        }
    }
    printf("%d\n",ans);
}