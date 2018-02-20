#include <string>
#include <iostream>
using namespace std;

string inp;

int main()
{
    cin >> inp;
    int len = inp.length();

    int ans = 1;
    inp += inp;    
    
    for(int i = 0; i < len; ++i){
        int flag = 0;

        for(int k = 0; k < i; ++k){
            for(int l = 0; l < len; ++l){
                if(inp[i+l] != inp[k+l]){
                    flag++;
                    break;
                }
            }
        }
        if(flag == i) ans++;
    }

    printf("%d\n", ans-1);
}