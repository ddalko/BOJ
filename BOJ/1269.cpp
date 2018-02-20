#include <bits/stdc++.h>

using namespace std;

int n, m, x;

int main()
{
    map<int,int> M;
    map<int,int>::iterator it;

    scanf("%d %d",&n,&m);
    for(int i = 0; i < n+m; ++i){
        scanf("%d",&x);
        it = M.find(x);
        if(it != M.end()) M[x]--;
        else M[x]++;       
    }
    
    int ans = 0;
    for(it = M.begin(); it != M.end(); ++it){
        if(it->second > 0) ans++;
    }
    printf("%d\n",ans);
}