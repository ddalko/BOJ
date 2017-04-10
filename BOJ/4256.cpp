#include <cstdio>

const int MAXN = 1000;

int n;
int pre[MAXN+5];
int in[MAXN+5];

void f(int l, int r, int k)
{
	for(int i = l; i < r; ++i){
		if(pre[k] == in[i]){
			f(l, i, k+1);
			f(i+1, r, k+i-l+1);			
			printf("%d ",pre[k]);
			return ;
		}
	}
}

int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) scanf("%d",pre+i);
		for(int i = 0; i < n; ++i) scanf("%d",in+i);

		f(0, n, 0);
		printf("\n");
	}
}