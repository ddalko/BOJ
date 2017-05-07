#include <bits/stdc++.h>

using namespace std;

int a, b, x;
map<int,int> m;
map<int,int>::iterator it;

int main()
{
    scanf("%d %d",&a,&b);
    for(int i = 0; i < a; ++i){
        scanf("%d",&x);
        m.insert(make_pair(x, 1));
    }

    int ans = 0;
    for(int i = 0; i < b; ++i){
        scanf("%d",&x);
        it = m.find(x);
        if(it != m.end()) {
            m[x]--;
            ans++;
        }
    }

    printf("%d\n",a-ans);
    for(it = m.begin(); it != m.end(); ++it){
        if(it->second > 0) printf("%d ",it->first);
    }
}
