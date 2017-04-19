#include <cstdio>

int n, a, p;
int arr[55];

int main()
{
    scanf("%d %d %d",&n,&a,&p);
    for(int i = 0; i < n; ++i) scanf("%d", arr+i);

    int r = 1; int k = 1;
    for(int i = 0; i < n; ++i){
        if(arr[i] > a) r++;
        if(arr[i] >= a) k++;
    }
    (k <= p) ? printf("%d\n",r) : puts("-1");
}