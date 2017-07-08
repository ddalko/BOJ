#include <cstdio>

int n;
int ed[105];

int main()
{
    int q;
    scanf("%d %d",&n,&q);
    
    for(int task = 0; task < q; ++task){
        int t, k, d;
        scanf("%d %d %d",&t,&k,&d);
        
        int id;
        int ans = 0;
        int ve[105];
        for(id = 1; id <= n; ++id){
            ve[id] = 0;

            if(k == 0) break;
            else{
                if(ed[id] < t){
                    ans += id;
                    ve[id] = t + d - 1;
                    k--;
                }
            }
        }

        if(k == 0){
            printf("%d\n", ans);
            for(int i = 1; i <= id; ++i){
                if(ve[i] > 0){
                    ed[i] = ve[i];
                }
            }
        }else{
            printf("-1\n");
        }
    }
}
