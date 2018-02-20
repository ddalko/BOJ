#include <cstdio>
<<<<<<< HEAD
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef long long lld;

int n, m;
int team[1005][2]; //0 : 득 1: 실

lld f(int idx)
{
	return ((lld)team[idx][0]*team[idx][0])*1000 / ((team[idx][0]*team[idx][0])+(team[idx][1]*team[idx][1]));
}
=======

int n, m;
int team[1005][2]; // 0 : 득 1 : 실
int exp[1005];
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&m);
<<<<<<< HEAD
		for(int i = 1; i <= n; ++i) team[i][0] = team[i][1] = 0;

		for(int i = 0; i < m; ++i){
			int a, b, p, q;
			scanf("%d %d %d %d",&a,&b,&p,&q);
			team[a][0] += p; team[b][1] += p;
			team[a][1] += q; team[b][0] += q;
		}	

		lld Mini = 2e17;
		lld Maxi = 0;

		for(int i = 1 ; i <= n; ++i){
			if(team[i][0] == 0 && team[i][1] == 0){
				Mini = MIN(Mini, 0LL);
				Maxi = MAX(Maxi, 0LL);				
				continue;
			}
			Mini = MIN(Mini, f(i));	
			Maxi = MAX(Maxi, f(i));
		}
		printf("%lld\n",Maxi);
		printf("%lld\n",Mini);
	}
	
=======
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
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432
}