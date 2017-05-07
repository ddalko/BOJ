#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > p;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        p.emplace_back(make_pair(b, a));
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; ++i) printf("%d %d\n",p[i].second,p[i].first);
}