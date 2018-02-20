#include <cstdio>
#include <queue>
using namespace std;

int n;
char inp[200005];
queue<int> r;
queue<int> d;

int main()
{
    scanf("%d",&n);
    scanf("%s",inp);

    for(int i = 0; i < n; ++i){
        if(inp[i] == 'R') r.push(i);
        else if(inp[i] == 'D') d.push(i);
    }

    while(1)
    {
        if(d.empty()) {
            puts("R");
            return 0;
        }else if(r.empty()){
            puts("D");
            return 0;
        }

        if(d.front() < r.front()){
            r.pop();
            int v = d.front();
            d.pop();
            d.push(n + v);
        }else{
            d.pop();
            int v = r.front();
            r.pop();
            r.push(n + v);
        }
    }
}