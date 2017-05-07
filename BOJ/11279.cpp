#include <bits/stdc++.h>

using namespace std;

int n, x;
priority_queue<int> pq;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        if(x){
            pq.push(x);
        }else{
            if(pq.empty()) puts("0");
            else {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
    }
}