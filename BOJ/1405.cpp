#include <cstdio>

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n;
double ans;
double p[4];
bool board[100][100];

void f(int y, int x, int c, double prob)
{
    if(board[y][x]) return ;
    if(c == n) {
        ans += prob;
        return ;
    }

    board[y][x] = true;
    
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];

        f(ny, nx, c+1, prob * p[i]);
    }

    board[y][x] = false;
}

int main()
{
    int a;
    scanf("%d",&n);

    for(int i = 0; i < 4; ++i){
        scanf("%d",&a);
        p[i] = a / 100.0;
    }
    
    ans = 0;
    f(50, 50, 0, 1);
    printf("%.10f",ans);
}