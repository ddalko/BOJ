#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char board[51][51];

int chk()
{
    int ret = 1;

    for(int i = 0; i < n; ++i){
        int r = 1, c = 1;
        for(int j = 0; j < n-1; ++j){
            if(board[i][j] == board[i][j+1]) r++;
            else{
                ret = max(ret, r);
                r = 1;
            }
            ret = max(ret, r);

            if(board[j][i] == board[j+1][i]) c++;
            else{
                ret = max(ret, c);
                c = 1;
            }
            ret = max(ret, c);
        }
    }

    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%s",board[i]);

    int ans = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-1; ++j){
            if(board[i][j] != board[i][j+1]){
                swap(board[i][j], board[i][j+1]);
                ans = max(ans, chk());
                swap(board[i][j], board[i][j+1]);         
            }

            if(board[j][i] != board[j+1][i]){
                swap(board[j][i], board[j+1][i]);
                ans = max(ans, chk());
                swap(board[j][i], board[j+1][i]);   
            }           
        }
    }

    printf("%d\n",ans);
}