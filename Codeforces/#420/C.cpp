#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n;
vector<int> stk;

int main()
{
    string op;
    int x, ans = 0;
    int ttop = 1;
    cin >> n;

    for(int i = 0; i < 2 * n; ++i){
        cin >> op;
        
        if(op.compare("add") == 0){
            scanf(" %d ",&x);
            stk.push_back(x);
        }else{
            if(!stk.empty()){
                if(stk.back() == ttop){
                    stk.pop_back();
                }else{
                    ans++;
                    stk.clear();
                }
            }
            ttop++;
        }
    }
    printf("%d\n",ans);
}