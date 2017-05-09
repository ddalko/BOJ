#include <cstdio>

int n;
int arr[1005][2];

int main()
{
    scanf("%d",&n);
    bool changed = false;
    bool nincreased = false;
    for(int i = 0; i < n; ++i){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        if(arr[i][0] != arr[i][1]) changed = true;
        if(i-1 > 0 && !nincreased && arr[i-1][1] < arr[i][1]) nincreased = true;
    }

    if(changed) {
        puts("rated");
    }else if(nincreased){
        puts("unrated");
    }else {
        puts("maybe");
    }    
}