#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> rc[105][105];
char board[105][105];
vector<int> g[10005];

bool visited[10005];
int bMatched[10005];

bool dfs(int cur)
{
	visited[cur] = true;
	for(int i = 0; i < (int)g[cur].size(); ++i){
		int B = g[cur][i];
		if(bMatched[B] == -1 || !visited[bMatched[B]] && dfs(bMatched[B])){
			bMatched[B] = cur;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%s",board[i]);

	int rIdx = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			while(board[i][j] == '.' && j < n) rc[i][j++].first = rIdx;
			rIdx++;
		}
	}

	int cIdx = 0;
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n; ++i){
			while(board[i][j] == '.' && i < n) rc[i++][j].second = cIdx;
			cIdx++;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == '.'){
				int a = rc[i][j].first;
				int b = rc[i][j].second;
				g[a].push_back(b);
			}
		}
	}
	for(int i = 0; i <= cIdx; ++i) bMatched[i] = -1;

	int ans = 0;
	for(int i = 0; i < rIdx; ++i){
		for(int j = 0; j <= rIdx; ++j) visited[j] = false;
		if(dfs(i)) ans++;
	}
	printf("%d\n",ans);
}