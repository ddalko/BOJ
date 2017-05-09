#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N, m, M, T, R;
    scanf("%d %d %d %d %d",&N,&m,&M,&T,&R);

    int ans = 0, i = 0, mini = m;
    if(mini + T > M) {
        puts("-1");
        return 0;
    }
    while(i < N){
        if(m + T <= M){
            i++;
            ans++;
            m += T;
        }else{
            ans++;
            m = max(m - R, mini);
        }
    }
    printf("%d\n",ans);
}