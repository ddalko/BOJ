#include <cstdio>
#include <algorithm>

using namespace std;

int x;
int arr[10];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        for(int i = 0; i < 10; ++i) scanf("%d",arr+i);
        sort(arr, arr+10);
        printf("%d\n",arr[7]);
    }
}