#include <cstdio>

int n, k;
int a[21];

bool dfs(int idx, int sum)
{
	if(idx == n) return sum == k;
	if(dfs(idx+1, sum)) return true;
	if(dfs(idx+1, sum+a[idx])) return true;
	return false; 
}

int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; ++i) scanf("%d",a+i);
	if(dfs(0, 0)) printf("YES\n");
	else printf("NO\n");
}