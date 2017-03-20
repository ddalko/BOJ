#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int board[301][301];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		int l, ix, iy;
		int dstx,dsty;
		scanf("%d",&l);
		scanf("%d %d",&ix,&iy);
		scanf("%d %d",&dstx,&dsty);

		for(int i = 0; i < l; ++i) for(int j = 0; j < l; ++j) board[i][j] = -1;

		queue< pair<int,int> > q;
		q.push(make_pair(ix,iy));
		board[iy][ix] = 0;

		int ans = 0;
		while(q.size()){
			int curx = q.front().first;
			int cury = q.front().second;
			int move = board[cury][curx];
			q.pop();

			if(curx == dstx && cury == dsty){
				ans = move;
				break;
			}

			for(int i = 0; i < 8; ++i){
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if(nx >= 0 && nx < l && ny >= 0 && ny < l){
					if(board[ny][nx] == -1){
						board[ny][nx] = move + 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}