#include <bits/stdc++.h>

using namespace std;

int n, x;
int arr[100005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);
    sort(arr, arr+n);

    int ans = 0;
    scanf("%d",&x);
    for(int i = 0; i < n; ++i){
        if(x <= arr[i]) break;
        if(binary_search(arr+i+1, arr+n, x-arr[i])) ans++;
    }
    printf("%d\n",ans);
}