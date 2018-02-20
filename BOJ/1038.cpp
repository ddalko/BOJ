#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int N;
set<lld> s;

void f(int n, string a)
{
    for(int i = n-1; i >= 0; --i){
        string temp = a;
        temp += (i + '0');
        lld e = atoll(temp.c_str());
        s.insert(e);
        f(i, temp);
    }
}

int main()
{
    s.insert(0);
    string a = "";
    for(lld i = 1; i <= 9; ++i){
        s.insert(i);
        a = i + '0';
        f(i, a);
    }

    scanf("%d",&N);
    lld ans = 0;
    if(s.size() < N+1){
        puts("-1");
    }else{
        for(auto it = s.begin(); it != s.end(); it++, N--){
            ans = *it;
            if(N == 0) break;
        }
        printf("%lld", ans);
    }

    
}