#include <cstdio>
#include <algorithm>

#define min(a,b) (((a) < (b)) ? (a) : (b))

struct V{
	int src, dst;
	int box;
};

bool cmp(const V lsh, const V rsh)
{
	if(lsh.src == rsh.src) return lsh.dst < rsh.dst;
	return lsh.src < rsh.src;
}

int n, c, m;
V v[10001];

int main()
{
	scanf("%d %d %d",&n,&c,&m);
	for(int i = 0; i < m; ++i) scanf("%d %d %d",&v[i].src,&v[i].dst,&v[i].box);

	std::sort(v, v+m, cmp);

	int ans = 0;
	int curW = 0; int idx = 0;

	for(int i = 0; i < m; ++i){
		
	}
	printf("%d\n",ans);
}