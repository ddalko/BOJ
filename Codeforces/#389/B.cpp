#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char,char> pcc;

int h[26];
char inp1[1005];
char inp2[1005];

int main()
{
    scanf("%s %s",inp1,inp2);

    vector<pcc> ans;
    
    for(int i = 0; inp1[i]; ++i){
        int aIdx = inp1[i]-'a';
        int bIdx = inp2[i]-'a';

        if(inp1[i] == inp2[i]){
            if(h[aIdx] == 0){
                h[aIdx] = inp2[i];
            }else{
                if(h[aIdx] != inp2[i]) {
                    puts("-1");
                    return 0;
                }
            }
        }else{
            if(h[aIdx] == 0 && h[bIdx] == 0){
                h[aIdx] = inp2[i];
                h[bIdx] = inp1[i];
                ans.push_back(make_pair(inp1[i], inp2[i]));
            }else{
                if(h[aIdx] != inp2[i] || h[bIdx] != inp1[i]){
                    puts("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); ++i){
        printf("%c %c\n", ans[i].first, ans[i].second);
    }
}