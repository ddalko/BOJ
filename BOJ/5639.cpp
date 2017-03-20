#include <cstdio>

int t[10001];

void traversal(int l, int r)
{
	if(l == r) return;
	if(l+1 == r){
		printf("%d\n", t[l]);
		return ;
	}

	int nr = l + 1;
	for(; nr < r && t[nr] < t[l]; nr++);
	traversal(l+1, nr);
	traversal(nr, r);
	printf("%d\n", t[l]);
}

int main()
{
	int x, i = 0;
	while(scanf("%d",&x) != -1){
		t[i++] = x;
	}
	traversal(0, i);
}