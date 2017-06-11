#include <cstdio>

int n, k;
int arr[105];
int rep[105];

int main()
{
    scanf("%d %d",&n,&k);

    int cnt = 0;
    int idx = -1;
    for(int i = 0; i < n; ++i) {
        int a = 0;
        scanf("%d",&a);
        arr[i] = a;
        if(a == 0) {
            idx = i;
            cnt++;
        }
    }

    for(int i = 0; i < k; ++i) scanf("%d",rep+i);
    
    if(cnt == 1){
        arr[idx] = rep[0];
        
        for(int i = 0; i < n-1; ++i){
            if(arr[i] > arr[i+1]) {
                printf("Yes");
                return 0;
            }
        }
        puts("No");
    }else puts("Yes");
}