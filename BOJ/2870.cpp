#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
char inp[105];
vector<string> a;

bool cmp(const string& lhs, const string& rhs)
{
    if(lhs.size() == rhs.size()){
        for(int i = 0; i < lhs.size(); ++i){
            if(lhs[i] == rhs[i]) continue;
            return lhs[i] < rhs[i];
        }
    }
    return lhs.size() < rhs.size();
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%s",inp);
        int len = strlen(inp);

        for(int j = 0; j < len; j++){
            string tmp = "";
            if(inp[j]-'0' == 0) continue;
            while(0 <= (inp[j]-'0') && (inp[j]-'0') < 10 && j < len){tmp += inp[j++];}
            if(tmp != "") a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end(), cmp);
    
    for(int i = 0; i < (int)a.size(); ++i) cout << a[i] << '\n';
}