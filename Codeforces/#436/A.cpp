#include <bits/stdc++.h>
using namespace std;

int n;
int card[101];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);
        card[x]++;
    }

    int a[2] = {0, 0};
    int b[2] = {-1, -1};
    int o = 0;

    for(int i = 1; i <= 100; ++i){
        if(o == 2) break;
        if(card[i] > 0){
            a[o] += card[i];
            b[o] = i;
            o++;
        }
    }

    if(a[0] == a[1] && n / 2 == a[0]){
        puts("YES");
        printf("%d %d\n", b[0], b[1]);
    }else{
        puts("NO");
    }
}