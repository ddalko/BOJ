<<<<<<< HEAD
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
=======
#include <cstdio>
#include <vector>

using namespace std;

int n, vcnt;
char board[105][105];

int bM[10005], visited[10005];
pair<int,int> rc[105][105];
vector<int> g[10005];

int dfs(int cur)
{
	if(visited[cur] == vcnt) return 0;
	visited[cur] = vcnt;

	for(int i = 0; i < (int)g[cur].size(); ++i){
		int B = g[cur][i];
		if(bM[B] == -1 || dfs(bM[B])){
			bM[B] = cur;
			return 1;
		}
	}
	return 0;
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%s",board[i]);

<<<<<<< HEAD
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
=======
	int rIdx = 0, cIdx = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == '.'){
				if(j == 0 || board[i][j-1] == 'X') rIdx++;
				rc[i][j].first = rIdx;
			}

			if(board[j][i] == '.'){
				if(j == 0 || board[j-1][i] == 'X') cIdx++;
				rc[j][i].second = cIdx;
			}
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == '.'){
				int a = rc[i][j].first;
				int b = rc[i][j].second;
<<<<<<< HEAD
				g[a].push_back(b);
			}
		}
	}
	for(int i = 0; i <= cIdx; ++i) bMatched[i] = -1;

	int ans = 0;
	for(int i = 0; i < rIdx; ++i){
		for(int j = 0; j <= rIdx; ++j) visited[j] = false;
		if(dfs(i)) ans++;
=======
				g[a].emplace_back(b);
			}
		}
	}

	for(int i = 0; i <= cIdx; ++i) bM[i] = -1;
	int ans = 0; vcnt = 0;
	for(int i = 1; i <= rIdx; ++i){
		vcnt++;
		ans += dfs(i);
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432
	}
	printf("%d\n",ans);
}