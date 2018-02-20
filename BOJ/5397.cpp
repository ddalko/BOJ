#include <bits/stdc++.h>

using namespace std;

char inp[1000005];

int main()
{
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%s", inp);

        list<char> ans;
        auto iter = ans.begin();

        for(int i = 0; inp[i]; ++i){
            if(inp[i] == '<'){
                if(iter != ans.begin()) iter--;
            }else if(inp[i] == '>'){
                if(iter != ans.end()) iter++;
            }else if(inp[i] == '-'){
                if(iter != ans.begin()) iter = ans.erase(--iter);
            }else{
                iter = ++ans.insert(iter, inp[i]);
            }
        }

        for(iter = ans.begin(); iter != ans.end(); ++iter){
            printf("%c",*iter);
        }
        puts("");        
    }
}