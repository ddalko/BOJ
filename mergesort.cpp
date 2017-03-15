#include <cstdio>

const int MAXN = 1000000;

int arr[MAXN+1];
int tmp[MAXN+1];

void msort(int l,int r)
{
	if(l == r) return ;
	int m = (l + r) / 2;
	msort(l, m);
	msort(m + 1, r);

	int p = l;
	int lp = l;
	int rp = m + 1;

	while(lp <= m && rp <= r){
		if(arr[lp] <= arr[rp]) tmp[p++] = arr[lp++];
		else tmp[p++] = arr[rp++];
	}
	while(lp <= m) tmp[p++] = arr[lp++];
	while(rp <= r) tmp[p++] = arr[rp++];

	for(int i = l; i <= r; ++i) arr[i] = tmp[i];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",arr+i);

	msort(0,n-1);

	for(int i = 0; i < n; ++i) printf("%d ",arr[i]);
	puts("");
}