#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int goalState = 123456780;
int board[3][3];
int tmp[3][3];

int main()
{
	for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) scanf("%d",&board[i][j]);

	int iState = 0;	
	for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) iState *= 10, iState += board[i][j];
	
	int ans = -1;
	queue<int> q;
	map<int, int> m;
	map<int, int>::iterator it;

	q.push(iState);
	m.insert(m.begin(), make_pair(iState, 0));

	while(!q.empty()){
		int state = q.front();
		int t = 0;
		it = m.find(state);
		t = (*it).second;

		q.pop();

		if(state == goalState) {
			it = m.find(state);
			ans = (*it).second;
			break;
		}

		int posx, posy;
		for(int i = 2; i >= 0; --i){
			for(int j = 2; j >= 0; --j){
				board[i][j] = state % 10;
				if(state % 10 == 0) posx = j, posy = i;
				state /= 10;				
			}
		}

		for(int i = 0; i < 4; ++i){
			int nx = posx + dx[i];
			int ny = posy + dy[i];

			if(nx >= 0 && ny >= 0 && ny < 3 && nx < 3){
				for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) tmp[i][j] = board[i][j];
				tmp[posy][posx] = tmp[ny][nx];
				tmp[ny][nx] = 0;

				int nState = 0;
				for(int y = 0; y < 3; ++y) for(int x = 0; x < 3; ++x) nState *= 10, nState += tmp[y][x];

				it = m.find(nState);
				if(it == m.end()) {
					m.insert(m.begin(), make_pair(nState, t+1));
					q.push(nState);
				}
			}
		}
	}
	printf("%d\n",ans);	
}