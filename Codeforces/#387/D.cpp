#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int temp[200005];
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    scanf("%d %d",&n,&k);

    int ncnt = 0;
    int pdays = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", temp+i);

        if(temp[i] >= 0){
            pdays++;
        }else{
            if(pdays != 0) {
                pq.push(pdays);
                pdays = 0;
            }
            ncnt++;
        }
    }
    if(pdays != 0) pq.push(pdays);
    
    int ans = 0;
    if(ncnt > k){
        puts("-1");
        return 0;
    }else{
        k -= ncnt;
        ans += (int)pq.size() * 2;

        while(!pq.empty()){
            if(k - pq.top() >= 0){
                k -= pq.top();
                pq.pop();
                ans--;
            }else{
                break;
            }
        }
        printf("%d\n", ans);
    }
}