#include <cstdio>
#include <algorithm>

using namespace std;

int inp1[26];
int inp2[26];
char a[1005];
char b[1005];

int main()
{
    while(gets(a)){
        gets(b);
        for(int i = 0; i < 26; ++i) inp1[i] = inp2[i] = 0;

        for(int i = 0; a[i]; ++i) inp1[a[i] - 'a']++;
        for(int i = 0; b[i]; ++i) inp2[b[i] - 'a']++;

        for(int i = 0; i < 26; ++i){
            int tmp = min(inp1[i], inp2[i]);
            while(tmp--) printf("%c",i+'a');
        }
        puts("");
    }
}