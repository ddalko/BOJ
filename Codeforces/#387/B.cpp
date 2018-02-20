#include <cstdio>
#include <string>
using namespace std;

int len;
char s[256];

int cnt[4]; //ACGT

int main()
{
    scanf("%d", &len);
    scanf("%s", s);
    
    if(len % 4 == 0){
        for(int i = 0; i < 4; ++i) cnt[i] = len / 4;

        for(int i = 0; i < len; ++i){
            if(s[i] == 'A') cnt[0]--;
            else if(s[i] == 'C') cnt[1]--;
            else if(s[i] == 'G') cnt[2]--;
            else if(s[i] == 'T') cnt[3]--;
        }

        for(int i = 0; i < len; ++i){
            if(s[i] == '?'){
                for(int k = 0; k < 4; ++k){
                    if(cnt[k] > 0){
                        if(k == 0) s[i] = 'A';
                        else if(k == 1) s[i] = 'C';
                        else if(k == 2) s[i] = 'G';
                        else if(k == 3) s[i] = 'T';
                        cnt[k]--;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < 4; ++i){
            if(cnt[i] != 0){
                puts("===");
                return 0;
            }
        }

        printf("%s\n", s);
    }else{
        puts("===");
        return 0;
    }
}