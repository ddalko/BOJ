#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, x;
priority_queue<pair<int,int> > pq;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        if(x > 0){
            pq.push(make_pair(-x, 0));
        }else if(x < 0){
            pq.push(make_pair(x, 1));    
        }else{
            if(!pq.empty()){
                pq.top().second ? printf("%d\n",pq.top().first) : printf("%d\n",-pq.top().first);
                pq.pop();
            }else puts("0");
        }
    }    
}