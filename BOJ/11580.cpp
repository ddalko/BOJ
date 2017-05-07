#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int n;
char inp[1005];
set<pii> M;

int main()
{
    int cx = 0, cy = 0;
    M.insert(mp(cx, cy));

    scanf("%d",&n);
    scanf("%s",inp);
    for(int i = 0; i < n; ++i){
        if(inp[i] == 'S') cy--;
        else if(inp[i] == 'E') cx++;
        else if(inp[i] == 'N') cy++;
        else if(inp[i] == 'W') cx--;
    
        M.insert(mp(cx, cy));
    }
    printf("%d\n",M.size());
}