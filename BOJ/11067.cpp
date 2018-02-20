#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct P{
	int x, y;
};

bool cmp(const P lhs, const P rhs)
{
	if(lhs.x == rhs.x) return lhs.y < rhs.y;
	return lhs.x < rhs.x;
}

bool cmp2(const P lhs, const P rhs)
{
	if(lhs.x == rhs.x) return lhs.y > rhs.y;
	return lhs.x < rhs.x;
}

int n, m;
P p[100001];

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		memset(p, 0, sizeof(p));
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) scanf("%d %d",&p[i].x,&p[i].y);
		sort(p, p+n, cmp);

		
		if(p[0].y != 0){
			int t = 0;
			while(t < n && p[t].x == 0) t++;
			sort(p, p+t, cmp2);
		}

		for(int i = 0; i < n - 1; ++i){
			if(p[i].x != p[i+1].x && p[i].y != p[i+1].y){
				int _x = p[i+1].x;
				int t = i + 1;
				while(t < n && p[t++].x == _x);

				sort(p+i+1, p+t, cmp2);
			}
		}

		scanf("%d",&m);
		for(int i = 0; i < m; ++i){
			int q;
			scanf("%d",&q);
			printf("%d %d\n",p[q-1].x,p[q-1].y);
		}
	}
}