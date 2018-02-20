#include <cstdio>

int n, m;
int arr[10006];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%d",arr+i);

    int l, r, x;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d",&l,&r,&x);
        l--;
        r--;
        x--;

        int pos1 = x - l;
        int cmp1 = 0;

        for(int j = l; j <= r; ++j){
            if(x == j) continue;
            if(arr[x] > arr[j]){
                cmp1++;
            }
        }

        if(pos1 == cmp1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}