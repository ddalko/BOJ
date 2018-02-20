#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

typedef pair<int,int> pii;

char board[12][7];

bool bfs(int y, int x, char c)
{
	bool ret = false;
	queue<pii> q;
	q.push(mp(y, x));
	int cnt = 1;
	board[y][x] = c-'A'+'a';

	while(q.size())
	{
		if(4 <= cnt) ret = true;

		int cy = q.front().first;
		int cx = q.front().second;
		board[cy][cx] = c-'A'+'a';
		q.pop();

		for(int i = 0; i < 4; ++i){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(0 <= ny && ny < 12 && 0 <= nx && nx < 6 && board[ny][nx] == c){
				q.push(mp(ny, nx));
				cnt++;
			}
		}
	}

	return ret;
}

void restore(int y, int x, char c)
{
	board[y][x] = c+'A'-'a';

	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(0 <= ny && ny < 12 && 0 <= nx && nx < 6 && board[ny][nx] == c){
			restore(ny, nx, c);
		}
	}	
}

void erase(int y, int x, char c)
{
	board[y][x] = '.';

	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(0 <= ny && ny < 12 && 0 <= nx && nx < 6 && board[ny][nx] == c){
			erase(ny, nx, c);
		}
	}
}

bool chk()
{
	bool ret = false;

	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < 6; ++j){
			if(board[i][j] != '.'){
				if(bfs(i, j, board[i][j])) {
					erase(i, j, board[i][j]);
					ret = true;
				}
				else restore(i, j, board[i][j]);
			}
		}
	}

	return ret;
}

void land()
{
	char tmp[13];

	for(int x = 0; x < 6; ++x){
		int p = 0;
		for(int i = 0; i < 12; ++i) tmp[i] = '.';
		for(int i = 11; i >= 0; --i) if(board[i][x] != '.') tmp[p++] = board[i][x];
		for(int i = 11; i >= 0; --i) board[i][x] = tmp[11-i];
	}
}

int main()
{
	for(int i = 0; i < 12; ++i) scanf("%s",board[i]);

	int ans = 0;
	while(chk()){
		land();
		ans++;
	}
	printf("%d\n",ans);
}