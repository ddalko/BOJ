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
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%s",board[i]);

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
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == '.'){
				int a = rc[i][j].first;
				int b = rc[i][j].second;
				g[a].emplace_back(b);
			}
		}
	}

	for(int i = 0; i <= cIdx; ++i) bM[i] = -1;
	int ans = 0; vcnt = 0;
	for(int i = 1; i <= rIdx; ++i){
		vcnt++;
		ans += dfs(i);
	}
	printf("%d\n",ans);
}