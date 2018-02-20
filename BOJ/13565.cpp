#include <cstdio>

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
bool ans;
char fabric[1005][1005];

void dfs(int y, int x)
{
    if(y >= n-1) {
        ans = true;
        return ;
    }

    fabric[y][x] = '1';

    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(fabric[ny][nx] =='0' && 0 <= ny && ny < n && 0 <= nx && nx < m){
            dfs(ny, nx);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) scanf("%s",fabric[i]);
    
    ans = false;
    for(int j = 0; j < m; ++j) {
        if(fabric[0][j] == '0') {
            dfs(0, j);
            if(ans) {
                puts("YES");
                return 0;
            }
        }
    }   
    puts("NO");
}