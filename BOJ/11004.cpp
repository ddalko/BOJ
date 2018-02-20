#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[5000005];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);
    nth_element(arr, arr+k-1, arr+n);
    printf("%d\n",arr[k-1]);
}