#include <bits/stdc++.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int MAXN=1000000;

int n;
int dp[MAXN+5][2];
vector<int> tree[MAXN+5];

void dfs(int cur, int p) {
  dp[cur][1] = 1;
  for (int nxt : tree[cur]) {
    if (nxt != p) {
      dfs(nxt, cur);
      dp[cur][0] += dp[nxt][1];
      dp[cur][1] += MIN(dp[nxt][0], dp[nxt][1]);
    }
  }
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	printf("%d\n",MIN(dp[1][0],dp[1][1]));
}