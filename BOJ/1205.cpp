#include <cstdio>
#define lld long long

lld score[51];

int main()
{
    int n, p;
    lld a;

    scanf("%d %lld %d",&n,&a,&p);
    for(int i = 0; i < n; ++i) scanf("%lld",score+i);

    int rank = 1; int cnt = 1;
    for(int i = 1; i < p; ++i) {
        if(score[i] == score[i-1]) cnt++;
        if(score[i] != score[i-1]) {
            rank += cnt;
            cnt = 1;
        }
        if(score[i] == a && score[i] != score[i+1]){
            printf("%d\n",rank);
            return 0;
        }
    }   
    puts("-1");
}
