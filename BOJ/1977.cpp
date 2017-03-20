#include <cstdio>

#define min(a,b) (((a) < (b)) ? (a) : (b))

bool flag[10001];

int main()
{
	int m, n, ans = 0, ans2 = 1e9;
	scanf("%d %d",&m,&n);
	for(int i = 1; i*i <= n; ++i) flag[i*i] = 1;
	for(int i = m; i <= n; ++i) {
		if(flag[i]) {
			ans += i;
			ans2 = min(i, ans2);
		}
	}
	if(ans2 == 1e9) printf("-1\n");
	else printf("%d\n%d\n",ans, ans2);
}