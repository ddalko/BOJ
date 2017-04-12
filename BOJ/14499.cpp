#include <cstdio>

int dice[6];
int map[21][21];
int n, m, x, y, k;

void east()
{
	int tmp;
	tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[3];
	dice[3] = dice[2];
	dice[2] = tmp;
}

void west()
{
	int tmp;
	tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[5];
	dice[5] = tmp;
}

void north()
{
	int tmp;
	tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[4];
	dice[4] = dice[5];
	dice[5] = tmp;
}

void south()
{
	int tmp;
	tmp = dice[0];
	dice[0] = dice[5];
	dice[5] = dice[4];
	dice[4] = dice[2];
	dice[2] = tmp;
}

int f(int d)
{
	int ret = -1;
	int tmp;
	if(d == 1){
		if(x+1 < m) {
			east();
			if(map[y][x+1] == 0) map[y][x+1] = dice[5];
			else {
				dice[5] = map[y][x+1];
				map[y][x+1] = 0;
			}
			ret = dice[2];
			x = x+1;
		}
	}else if(d == 2){
		if(0 <= x-1){
			west();
			if(map[y][x-1] == 0) map[y][x-1] = dice[5];
			else {
				dice[5] = map[y][x-1];
				map[y][x-1] = 0;
			}
			ret = dice[2];
			x = x-1;
		}
	}else if(d == 3){
		if(0 <= y-1){
			north();
			if(map[y-1][x] == 0) map[y-1][x] = dice[5];
			else {
				dice[5] = map[y-1][x];
				map[y-1][x] = 0;
			}
			ret = dice[2];
			y = y-1;
		}
	}else if(d == 4){
		if(y+1 < n){
			south();
			if(map[y+1][x] == 0) map[y+1][x] = dice[5];
			else {
				dice[5] = map[y+1][x];
				map[y+1][x] = 0;
			}
			ret = dice[2];
			y = y+1;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);

	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d",&map[i][j]);

	for(int i = 0; i < k; ++i){
		int op;
		scanf("%d",&op);
		int ans = f(op);
		if(ans != -1) printf("%d\n",ans);
	}
}