#include <bits/stdc++.h>

using namespace std;

int n, x;
string op;
queue<int> q;

int main()
{
    for(scanf("%d",&n);n--;){
        cin >> op;
        if(op.compare("push") == 0){
            cin >> x;
            q.push(x);
        }else if(op.compare("front") == 0){
            if(q.empty()) puts("-1");
            else printf("%d\n",q.front());
        }else if(op.compare("back") == 0){
            if(q.empty()) puts("-1");
            else printf("%d\n",q.back());
        }else if(op.compare("size") == 0){
            printf("%d\n",q.size());
        }else if(op.compare("pop") == 0){
            if(q.empty()) puts("-1");
            else {
                printf("%d\n",q.front());
                q.pop();
            }
        }else if(op.compare("empty") == 0){
            printf("%d\n",q.empty());
        }
    }
}