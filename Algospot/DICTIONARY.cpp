#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
string inp[1006];
bool g[26][26];
bool visited[26];
bool d[26];
vector<char> ans;

void dfs(int cur)
{
    visited[cur] = true;

    bool f = false;
    for(int nxt = 0; nxt < 26; ++nxt){
        if(g[cur][nxt]){
            if(!visited[nxt]) dfs(nxt);
            f = true;
        }
    }

    ans.push_back(cur + 'a');
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> inp[i];
        memset(g, 0, sizeof(g));
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        ans.clear();

        bool invalid = false;
        for(int i = 0; i < n-1; ++i){
            int j = i+1;
            
            int l1 = inp[i].size();
            int l2 = inp[j].size();

            for(int k = 0; k < min(l1, l2); ++k){
                int a = inp[i][k] - 'a';
                int b = inp[j][k] - 'a';

                if(a != b) { // a < b
                    if(!g[b][a]) {
                        g[a][b] = true;
                        d[a] = true;
                    }
                    else invalid = true;
                    break;
                }
            }
        }

        for(int i = 0; i < 26; ++i){
            if(d[i] && !visited[i]){
                dfs(i);
            }
        }

        if(invalid) {
            puts("INVALID HYPOTHESIS");
            continue;
        }

        //is alphabet?
        bool isA = true;
        for(int i = 0; i < ans.size()-1; ++i){
            if(ans[i] < ans[i+1]){
                isA = false;
                break;
            }
        }

        if(isA){
            for(int i = 0; i < 26; ++i){
                printf("%c",i+'a');
            }
        }
        else{
            for(int i = 0; i < 26; ++i) d[i] = false;

            for(int i = ans.size()-1; i >= 0; --i){
                printf("%c",ans[i]);
                d[ans[i]-'a'] = true;
            }
            
            for(int i = 0; i < 26; ++i){
                if(!d[i]) printf("%c",i+'a');
            }
        }
        puts("");
    }
}   