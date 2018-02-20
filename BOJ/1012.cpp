#include <cstdio>

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int m, n;
bool field[55][55];

void dfs(int y,int x)
{
    field[y][x] = 0;

    for(int i = 0; i < 4; ++i){
    	int nx = x + dx[i];
    	int ny = y + dy[i];
    	if(nx >= 0 && nx < m && ny >= 0 && ny < n && field[ny][nx]) dfs(ny, nx);
    }
}

int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
    	int k;
        scanf("%d %d %d",&m,&n,&k);
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) field[i][j] = 0;
        
        for(int i = 0; i < k; ++i){
        	int y, x;
        	scanf("%d %d",&x,&y);
        	field[y][x] = 1;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
        	for(int j = 0; j < m; ++j){
        		if(field[i][j]){
        			dfs(i, j);
        			ans++;
        		}
        	}
        }

        printf("%d\n",ans);
    }
}
