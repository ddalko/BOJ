#include <cstdio>

int x;
int a[1000005];
int tmp[1000005];

void msort(int l, int r)
{
	if(l == r) return ;

	int m = (l + r) / 2;
	msort(l, m);
	msort(m+1, r);

	int p = l; int lp = l; int rp = m+1;
	while(lp <= m && rp <= r){
		if(a[lp] < a[rp]) tmp[p++] = a[lp++];
		else tmp[p++] = a[rp++];
	}	
	while(lp <= m) tmp[p++] = a[lp++];
	while(rp <= r) tmp[p++] = a[rp++];

	for(int i = l; i <= r; ++i) a[i] = tmp[i];
}

bool b_search(int l, int r)
{
	if(l == r){
		return a[l] == x;
	}
	int pivot = (l + r) / 2;
	if(a[pivot] < x) return b_search(pivot+1, r);
    return b_search(l, pivot);
}

int main()
{
	int t;
	for(scanf("%d",&t); t--;){
		int n, m;
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) scanf("%d",a+i);
		msort(0, n-1);

		scanf("%d",&m);
		for(int i = 0; i < m; ++i){
			scanf("%d",&x);
			printf("%d\n",b_search(0, n-1));
		}
	}	
}