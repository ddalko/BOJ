#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    map<string, int> m;

    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        string a, b;
        cin >> a >> b;
        
        if(b.compare("enter") == 0) {
            m[a]++;
        }else if(b.compare("leave") == 0){
            m[a]--;
        }
    }
    
    for(auto it = m.rbegin(); it != m.rend(); ++it){
        if(it->second > 0) printf("%s\n",it->first.c_str());
    }
}