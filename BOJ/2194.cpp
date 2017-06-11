#include <cstdio>

int n, m, k;
int a, b;
bool board[505][505];

int main()
{
    scanf("%d %d %d %d %d",&n,&m,&a,&b,&k);
    for(int i = 0; i < k; ++i){
        int i1,i2;
        scanf("%d %d",&i1,&i2);
        board[i1-1][i2-2] = true;
    }
    
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < b; ++j){
            board[i][j] = goal;
        }
    }
}