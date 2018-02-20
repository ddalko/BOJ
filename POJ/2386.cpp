#include <cstdio>

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, m;
char lake[101][101];

void dfs(int _y, int _x)
{
	lake[_y][_x] = '.';

	for(int d = 0; d < 8; ++d){
		int ny = _y + dy[d];
		int nx = _x + dx[d];

		if(nx >= 0 && nx < m && ny >= 0 && ny < n){
			if(lake[ny][nx] == 'W') dfs(ny, nx);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; ++i) scanf("%s",lake[i]);

	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(lake[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}