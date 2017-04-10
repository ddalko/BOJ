#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Team{
	int last;
	int cnt;
	int sum;
	int id;
};

bool cmp(const Team A, const Team B)
{
	if(A.sum == B.sum){
		if(A.cnt == B.cnt){
			return A.last < B.last;
		}
		return A.cnt < B.cnt;
	}
	return A.sum > B.sum;
}

int n, k, t, m;
int score[105][105];
Team team[105];

int main()
{
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d %d %d %d",&n,&k,&t,&m);

		for(int i = 0; i <= n; ++i) team[i].last = team[i].cnt = team[i].sum = 0;
		for(int i = 0; i <= n; ++i) for(int j = 0; j <= k; ++j) score[i][j] = 0;

		for(int i = 0; i < m; ++i){
			int a, b, c;
			scanf("%d %d %d",&a,&b,&c);
			if(score[a][b] < c) score[a][b] = c;
			team[a].id = a;
			team[a].cnt++;
			team[a].last = i;
		}

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= k; ++j){
				team[i].sum += score[i][j];
			}
		}

		sort(team+1, team+n+1, cmp);

		for(int i = 1; i <= n; ++i){
			if(team[i].id == t) {
				printf("%d\n",i);
				break;
			}
		}
	}
}