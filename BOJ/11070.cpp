#include <cstdio>

int n, m;
int team[1005][2]; // 0 : 득 1 : 실
int exp[1005];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&m);
		for(int i = 0; i < n; ++i) exp[i] = team[i][0] = team[i][1] = 0;

		for(int i = 0; i < m; ++i){
			int a, b, p, q;
			scanf("%d %d %d %d",&a,&b,&p,&q);	
			team[a][0] += p; team[b][1] += p;
			team[a][1] += q; team[b][0] += q;
		}

		for(int i = 0; i < n; ++i){
			if(team[i][0] != 0 && team[i][1] != 0){
				
			}
		}
	}
}