#include <cstdio>

char inp[200005];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",inp);
    
    bool d[4] = {0, 0, 0, 0}; // r l u d
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(inp[i] == 'R'){
            if(d[1]){
                d[1] = d[2] = d[3] = 0;
                ans++;
            }
            d[0] = 1;
        }else if(inp[i] == 'U'){
            if(d[3]){
                d[0] = d[1] = d[3] = 0;
                ans++;
            }
            d[2] = 1;
        }else if(inp[i] == 'L'){
            if(d[0]){
                d[0] = d[2] = d[3] = 0;
                ans++;
            }
            d[1] = 1;
        }else if(inp[i] == 'D'){
            if(d[2]){
                d[0] = d[1] = d[2] = 0;
                ans++;
            }
            d[3] = 1;
        }
    }
    printf("%d\n", ans+1);
}