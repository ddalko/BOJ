#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int v, e;
int c[505];
int g[505][505];

int main()
{
	scanf("%d %d",&v,&e);
	for(int i = 0; i < v; ++i) scanf("%d", c+i);
	for(int i = 0; i < v; ++i) for(int j = 0; j < v; ++j) g[i][j] = INF;
	
	for(int i = 0; i < e; ++i){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		g[a-1][b-1] = g[b-1][a-1] = c;
	}	

	int t;
	for(scanf("%d",&t);t--;){
		int x, y;
		scanf("%d %d",&x,&y);

		int ans = -1e9;
		for(int k = 0; k < v; ++k){
			for(int i = 0; i < v; ++i){
				for(int j = 0; j < v; ++j){
					g[i][j] = min(g[i][j], g[i][k] + g[k][j] + c[k]);
				}
			}
			if(g[x-1][y-1] != INF) ans = max(ans, g[x-1][y-1]);
		}
		printf("%d\n",ans);
	}
}