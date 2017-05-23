#include <cstdio>
#include <queue>

using namespace std;

int n, x;
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int> > minH;

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i){
        scanf("%d",&x);

        if(minH.size() == maxH.size()) maxH.push(x);
        else minH.push(x);

        if(!minH.empty() && !maxH.empty() && minH.top() < maxH.top()){
            int minTop = minH.top();
            int maxTop = maxH.top();
            minH.pop();
            maxH.pop();
            minH.push(maxTop);
            maxH.push(minTop);
        }

        printf("%d\n",maxH.top());
    }
}