#include <cstdio>

int n;
int pre[101];
int in[101];

void post(int l, int r, int k)
{
	for(int i = l; i < r; ++i){
		if(pre[k] == in[i]){
			post(l, i, k+1);
			post(i+1, r, k+i-l+1);
			printf("%d ",pre[k]);
			return ;
		}
	}
}

int main()
{
	int c;
	for(scanf("%d",&c);c--;){
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) scanf("%d",pre+i);
		for(int i = 0; i < n; ++i) scanf("%d",in+i);

		post(0, n, 0);
		printf("\n");
	}
}