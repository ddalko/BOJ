#include <bits/stdc++.h>

using namespace std;

int n, a;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
        scanf("%d",&a);
        pq.push(a);
    }

    int sum = 0;
    while((int)pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a+b;
        pq.push(a+b);
    }
    printf("%d\n", sum);
}