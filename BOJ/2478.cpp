#include <bits/stdc++.h>
using namespace std;
const int INF = 1234567890;
int n;
deque<int> d;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        d.push_back(x);
    }
    int l=0,r=0;
    int a=0,b=1;
 
    d.push_front(d.back());
    d.pop_back();
    int mcnt=1;
    for(int i=0;i<n;++i){
        int cnt = 1;
        while(cnt<n && d[(i+cnt+n-1)%n]==d[(i+cnt)%n]%n+1){
            ++cnt;
        }
        if(cnt>mcnt){
            l=i;
            r=(l+cnt-1+n)%n;
            mcnt=cnt;
        }
    }
    while(l>r){
        l=(l+1)%n;
        r=(r+1)%n;
        d.push_front(d.back());
        d.pop_back();
        ++b;
    }
    reverse(d.begin()+l,d.begin()+r+1);
    while(d[0]!=1){
        ++a;
        d.push_front(d.back());
        d.pop_back();
    }
    printf("%d %d %d %d",a,l+1,r+1,b);
}