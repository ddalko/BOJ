#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int y[100001];
int x[100001];

int main()
{
	scanf("%d %d",&n,&m);

	for(int i = 0; i < m; ++i) scanf("%d %d",y+i,x+i);

	sort(y, y+m); sort(x, x+m);
	
	int ans = 0;
	for(int i = 0; i < m; ++i){
		ans += abs(x[m/2] - x[i]);
		ans += abs(y[m/2] - y[i]);
	}
	printf("%d\n",ans);
}