#include <bits/stdc++.h>

using namespace std;

int n, m, a;

int main()
{
    map<int,int> M;
    map<int,int>::iterator it;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        
        it = M.find(a);
        if(it != M.end()) M[a]++;
        else M.insert(make_pair(a, 1));
    }

    for(scanf("%d",&m);m--;){
        scanf("%d",&a);

        it = M.find(a);
        if(it != M.end()) printf("%d ",M[a]);
        else printf("0 ");
    }
}