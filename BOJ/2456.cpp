#include <cstdio>
#include <algorithm>

using namespace std;

struct cand{
    int sum;
    int num;
    int cnt[4];

    bool operator < (const cand rhs)
    {
        if(sum != rhs.sum) return sum < rhs.sum;
        if(cnt[3] != rhs.cnt[3]) return cnt[3] < rhs.cnt[3];
        return cnt[2] < rhs.cnt[2];
    }
};

int n;
cand C[4];

int main()
{
    for(int i = 1; i <= 3; ++i) C[i].num = i;

    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int inp[4];
        for(int i = 1; i <= 3; ++i) scanf("%d",inp+i);

        for(int i = 1; i <= 3; ++i) {
            C[i].sum += inp[i];
            C[i].cnt[inp[i]]++;
        }
    }

    sort(C, C+4);
    if(C[2].sum == C[3].sum){
        if(C[2].cnt[3] == C[3].cnt[3]){
            if(C[2].cnt[2] == C[3].cnt[2]){
                printf("0 %d\n",C[3].sum);
                return 0;
            }
        }
    }
    printf("%d %d\n",C[3].num,C[3].sum);
}