#include <cstdio>

int n, m;
char board[505][505];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s", board[i]);

    int w = 0, h = 0;
    int x = 0, y = 0;

    for(int i = 0; i < n; ++i){
        int flag = false;
        for(int j = 0; j < m; ++j){

            if(board[i][j] == 'X') {
                y = i;
                x = j;
                flag = true;
            }

            while(board[i][j] == 'X' && j < m){
                w++;
                j++;
            }
        }
        if(flag) break;
    }

    while(board[y][x] == 'X' && y < n){
        h++;
        y++;
    }
    y -= h;

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(board[y+i][x+j] != 'X'){
                puts("NO");
                return 0;
            }else board[y+i][x+j] = '.';
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 'X'){
                puts("NO");
                return 0;
            }
        }
    }
    
    puts("YES");
    return 0;
}