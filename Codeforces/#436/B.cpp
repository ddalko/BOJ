#include <bits/stdc++.h>
using namespace std;

int n;
string inp;

inline bool isLower(char a)
{
    if('a' <= a && a <= 'z') return true;
    return false;
}

int main()
{
    cin >> n >> inp;

    set<char> s;
    int ans = -1e9;
    for(int i = 0; i < n; ++i){
        while(isLower(inp[i])){
            s.insert(inp[i]);
            ++i;
        }
        if((int)s.size() > ans){
            ans = (int)s.size();
        }
        s.clear();
    }
    printf("%d\n", ans);
}